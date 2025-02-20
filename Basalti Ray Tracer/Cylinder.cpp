#include "Cylinder.h"

Cylinder::Cylinder(const Vec3& center, double radius, double height)
    : center(center), radius(radius), height(height) {}

bool Cylinder::intersect(const Ray& ray, double& t) const {

    Vec3 oc = ray.origin - center;
    double a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
    double b = 2 * (oc.x * ray.direction.x + oc.z * ray.direction.z);
    double c = oc.x * oc.x + oc.z * oc.z - radius * radius;

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) return false;

    double sqrt_discriminant = std::sqrt(discriminant);
    double t0 = (-b - sqrt_discriminant) / (2 * a);
    double t1 = (-b + sqrt_discriminant) / (2 * a);

    t = (t0 < t1) ? t0 : t1;

    Vec3 hitPoint = ray.origin + ray.direction * t;
    if (hitPoint.y < center.y || hitPoint.y > center.y + height) return false;

    return t > 0;
}