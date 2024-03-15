#include "base/sphere.hpp"

namespace raytrc {
bool Sphere::hit(const Ray &ray, const double hitRange[2], HitResult &res) const 
{
    // Compute coefficients of the quadratic equation
    Vector3d oc = ray.origin() - mCenter;
    double a = ray.direction().normSquared();
    double bHalf = dot(oc, ray.direction());
    double c = oc.normSquared() - mRadius*mRadius;

    // Compute the discriminant
    double discriminant = bHalf*bHalf - a*c;

    // Check discriminat
    if (discriminant < 0) {
        // No hit
        return false;
    }

    // Compute the hit point
    double discriminantSqrt = std::sqrt(discriminant);
    double root = (-bHalf - discriminantSqrt)/a;
    if (!checkHitRange(hitRange, root)) {
        root = (-bHalf + discriminantSqrt)/a;
        if (!checkHitRange(hitRange, root)) {
            return false;
        }
    }

    // Record hit result
    res.t = root;
    res.p = ray.at(root);
    Vector3d outwardNormal = Vector3d((res.p - mCenter) / mRadius);
    res.setFaceNormal(ray, outwardNormal);

    return true;
}

} // namespace raytrc