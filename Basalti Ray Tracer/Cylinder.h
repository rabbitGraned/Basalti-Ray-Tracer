#ifndef CYLINDER_H
#define CYLINDER_H

#include <iostream>

#include "Vec3.h"
#include "Ray.h"

using namespace std;

struct Cylinder {
    Vec3 center;
    double radius;
    double height;

    Cylinder(const Vec3& center, double radius, double height);
    bool intersect(const Ray& ray, double& t) const;
};

#endif