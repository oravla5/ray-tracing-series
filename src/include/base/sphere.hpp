#ifndef INCLUDE_BASE_SPHERE_HPP
#define INCLUDE_BASE_SPHERE_HPP

#include "base/hittable.hpp"

namespace raytrc {

class Sphere : public Hittable {
public:
    Sphere(Vector3d center, double radius) : mCenter(center), mRadius(radius) {}

    bool hit(const Ray &ray, const double hitRange[2], HitResult &res) const override;

private:
    Vector3d mCenter;
    double mRadius;

};
} // namespace raytrc
#endif // INCLUDE_BASE_SPHERE_HPP