#include <iostream>
#include <algorithm>

#include "Cube.h"

using namespace std;

Cube::Cube(const Vec3& center, double size)
    : center(center), size(size) {}

bool Cube::intersect(const Ray& ray, double& t) const {

    // AABB (Axis-Aligned Bounding Box)
    double tMin = (center.x - size / 2 - ray.origin.x) / ray.direction.x;
    double tMax = (center.x + size / 2 - ray.origin.x) / ray.direction.x;

    if (tMin > tMax) std::swap(tMin, tMax);

    double tyMin = (center.y - size / 2 - ray.origin.y) / ray.direction.y;
    double tyMax = (center.y + size / 2 - ray.origin.y) / ray.direction.y;

    if (tyMin > tyMax) swap(tyMin, tyMax);

    if ((tMin > tyMax) || (tyMin > tMax)) return false;

    tMin = max(tMin, tyMin);
    tMax = min(tMax, tyMax);

    double tzMin = (center.z - size / 2 - ray.origin.z) / ray.direction.z;
    double tzMax = (center.z + size / 2 - ray.origin.z) / ray.direction.z;

    if (tzMin > tzMax) swap(tzMin, tzMax);

    if ((tMin > tzMax) || (tzMin > tMax)) return false;

    tMin = max(tMin, tzMin);
    tMax = min(tMax, tzMax);

    t = tMin;
    return t > 0;
}