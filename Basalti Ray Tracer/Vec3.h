#ifndef VEC3_H
#define VEC3_H

struct Vec3 {
    double x, y, z;

    Vec3(double x = 0, double y = 0, double z = 0);
    Vec3 operator+(const Vec3& v) const;
    Vec3 operator-(const Vec3& v) const;
    Vec3 operator*(double t) const;
    Vec3 operator/(double t) const;
    double dot(const Vec3& v) const;
    Vec3 normalize() const;
};

#endif