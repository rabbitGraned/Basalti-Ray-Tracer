#include "Sphere.h"

Sphere::Sphere(const Vec3& center, double radius)
    : center(center), radius(radius) {}

bool Sphere::intersect(const Ray& ray, double& t) const {
    Vec3 oc = ray.origin - center;
    double a = ray.direction.dot(ray.direction);
    double b = 2.0 * oc.dot(ray.direction);
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) return false;

    double sqrt_discriminant = std::sqrt(discriminant);
    double t0 = (-b - sqrt_discriminant) / (2.0 * a);
    double t1 = (-b + sqrt_discriminant) / (2.0 * a);

    t = (t0 < t1) ? t0 : t1;
    return t > 0;
}