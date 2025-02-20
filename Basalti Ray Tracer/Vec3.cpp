#include <cmath>
#include "Vec3.h"

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

Vec3 Vec3::operator+(const Vec3& v) const {
    return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::operator-(const Vec3& v) const {
    return Vec3(x - v.x, y - v.y, z - v.z);
}

Vec3 Vec3::operator*(double t) const {
    return Vec3(x * t, y * t, z * t);
}

Vec3 Vec3::operator/(double t) const {
    return Vec3(x / t, y / t, z / t);
}

double Vec3::dot(const Vec3& v) const {
    return x * v.x + y * v.y + z * v.z;
}

Vec3 Vec3::normalize() const {
    double len = std::sqrt(x * x + y * y + z * z);
    return Vec3(x / len, y / len, z / len);
}