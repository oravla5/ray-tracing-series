#ifndef INCLUDE_BASE_HITTABLE_HPP
#define INCLUDE_BASE_HITTABLE_HPP

#include "base/ray.hpp"

namespace raytrc {

class HitResult {
public:
    Vector3d p;
    Vector3d normal;
    double t;
    bool frontFace;

    void setFaceNormal(const Ray &ray, const Vector3d &outwardNormal)
    {
        // Sets the hit record normal vector.
        // NOTE: the parameter `outwardNormal` is assumed to have unit length.
        frontFace = dot(ray.direction(), outwardNormal) < 0;
        normal = frontFace ? outwardNormal : Vector3d(-outwardNormal);
    }
};

class Hittable {
public:
    virtual ~Hittable() = default;

    virtual bool hit(const Ray &ray, const double tRange[2], HitResult &res) const = 0;

protected:
    inline bool checkHitRange(const double hitRange[2], double t) const
    {
        return t <= hitRange[1] && t >= hitRange[0];
    }
};
} // namespace raytrc

#endif // INCLUDE_BASE_HITTABLE_HPP