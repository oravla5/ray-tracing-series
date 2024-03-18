#ifndef INCLUDE_HITTABLE_SPHERE_HPP
#define INCLUDE_HITTABLE_SPHERE_HPP

#include "scene/hittable.hpp"

namespace raytrc {

class Sphere : public Hittable {
public:
    Sphere(Vector3d center, double radius) : mCenter(center), mRadius(radius) {}

    bool hit(const Ray &ray, const Range &hitRange, HitResult &res) const override;

private:
    Vector3d mCenter;
    double mRadius;

};
} // namespace raytrc
#endif // INCLUDE_HITTABLE_SPHERE_HPP