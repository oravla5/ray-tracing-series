#ifndef INCLUDE_BASE_RAY_HPP
#define INCLUDE_BASE_RAY_HPP

#include "base/vector_3d.hpp"

namespace raytrc {
class Ray {
public:
    Ray() : mOrigin(), mDirection() {}
    Ray(const Vector3d &origin, const Vector3d &direction) : mOrigin(origin), mDirection(direction) {}

    Vector3d origin() const { return mOrigin; }
    Vector3d direction() const { return mDirection; }

    Vector3d at(double t) const 
    {
        return mOrigin + t * mDirection;
    }

private:
    Vector3d mOrigin;
    Vector3d mDirection;
};
} // namespace rayt
#endif // INCLUDE_BASE_RAY_HPP