#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>

#include "Vec3.h"
#include "Ray.h"

struct Sphere {
    Vec3 center;
    double radius;

    Sphere(const Vec3& center, double radius);
    bool intersect(const Ray& ray, double& t) const;
};

#endif