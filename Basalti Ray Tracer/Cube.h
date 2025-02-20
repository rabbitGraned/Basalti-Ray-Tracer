#ifndef CUBE_H
#define CUBE_H

#include "Vec3.h"
#include "Ray.h"

struct Cube {
    Vec3 center;
    double size;

    Cube(const Vec3& center, double size);
    bool intersect(const Ray& ray, double& t) const;
};

#endif