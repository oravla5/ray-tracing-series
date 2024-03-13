
#include "base/vector_3d.hpp"

namespace raytrc {

double dot(const Vector3d &lhs, const Vector3d &rhs) 
{
    return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
}

Vector3d cross(const Vector3d &lhs, const Vector3d &rhs) 
{
    return Vector3d(lhs.y() * rhs.z() - lhs.z() * rhs.y(),
                lhs.z() * rhs.x() - lhs.x() * rhs.z(),
                lhs.x() * rhs.y() - lhs.y() * rhs.x());
}

double Vector3d::norm() const 
{
    return std::sqrt(normSquared());
}

double Vector3d::normSquared() const 
{
    return mData[0]*mData[0] + mData[1]*mData[1] + mData[2]*mData[2];
}

Vector3d Vector3d::unit() const 
{
    return (*this)/norm();
}

Vector3d operator+(double s, const Vector3d &rhs) 
{
    return Vector3d(s + rhs.x(), s + rhs.y(), s + rhs.z());
}

Vector3d operator-(double s, const Vector3d &rhs) 
{
    return Vector3d(s - rhs.x(), s - rhs.y(), s - rhs.z());
}

Vector3d operator*(double s, const Vector3d &rhs) 
{
    return Vector3d(s * rhs.x(), s * rhs.y(), s * rhs.z());
}

std::ostream& operator<<(std::ostream &out, const Vector3d &v) 
{
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}
}