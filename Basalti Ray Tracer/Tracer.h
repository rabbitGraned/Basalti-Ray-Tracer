#ifndef RENDERER_H
#define RENDERER_H

#include <fstream>
#include <cmath>

#include "Vec3.h"
#include "Ray.h"
#include "Sphere.h"
#include "Cube.h"
#include "Cylinder.h"

using namespace std;

inline Vec3 shade(const Vec3& normal, const Vec3& lightDir) {
    double diffuse = max(0.0, normal.dot(lightDir));
    return Vec3(diffuse, diffuse, diffuse); //Direct Diffuse
}

template <typename T>
bool trace(const Ray& ray, const T& object, Vec3& hitPoint, Vec3& normal) {
    double t;
    if (!object.intersect(ray, t)) return false;

    hitPoint = ray.origin + ray.direction * t;
    normal = calculateNormal(hitPoint, object);
    return true;
}

inline Vec3 calculateNormal(const Vec3& hitPoint, const Sphere& sphere) {
    return (hitPoint - sphere.center).normalize();
}

inline Vec3 calculateNormal(const Vec3& hitPoint, const Cube& cube) {
    Vec3 d = (hitPoint - cube.center) / cube.size;
    double maxComponent = max(std::abs(d.x), max(abs(d.y), std::abs(d.z)));
    if (abs(d.x) == maxComponent) return Vec3(d.x > 0 ? 1 : -1, 0, 0);
    if (abs(d.y) == maxComponent) return Vec3(0, d.y > 0 ? 1 : -1, 0);
    return Vec3(0, 0, d.z > 0 ? 1 : -1);
}

inline Vec3 calculateNormal(const Vec3& hitPoint, const Cylinder& cylinder) {
    Vec3 d = hitPoint - cylinder.center;
    double dist = std::sqrt(d.x * d.x + d.z * d.z);
    return Vec3(d.x / dist, 0, d.z / dist);
}

template <typename T>
void render(const T& object, const Vec3& cameraPos, const Vec3& lightPos, int width, int height) {
    ofstream file("image.ppm");
    file << "P3\n" << width << " " << height << "\n255\n";

    double aspectRatio = static_cast<double>(width) / height;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {

            double u = (2.0 * (x + 0.5) / width - 1.0) * aspectRatio;
            double v = (1.0 - 2.0 * (y + 0.5) / height);

            Vec3 rayDir(u, v, 1); // rayDiraction
            rayDir = rayDir.normalize();

            Ray ray(cameraPos, rayDir);
            Vec3 hitPoint, normal;

            if (trace(ray, object, hitPoint, normal)) {
                Vec3 lightDir = (lightPos - hitPoint).normalize();
                Vec3 color = shade(normal, lightDir);
                file << static_cast<int>(color.x * 255) << " "
                    << static_cast<int>(color.y * 255) << " "
                    << static_cast<int>(color.z * 255) << "\n";
            }
            else {
                file << "0 0 0\n"; // Blackback
            }
        }
    }

    file.close();
}

#endif