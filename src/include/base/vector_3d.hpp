#ifndef INCLUDE_BASE_VECTOR_3D_HPP
#define INCLUDE_BASE_VECTOR_3D_HPP

#include "base/array_3d.hpp"

namespace raytrc {

class Vector3d : public Array3d {
public:
    Vector3d() : Array3d() {}
    Vector3d(double x, double y, double z) : Array3d(x, y, z) {}
    Vector3d(const Array3d &array3d) : Array3d(array3d) {}

    inline double x() const { return (*this)[0]; }
    inline double y() const { return (*this)[1]; }
    inline double z() const { return (*this)[2]; }

    double norm() const;
    double normSquared() const;
    Vector3d unit() const;

    friend double dot(const Vector3d &lhs, const Vector3d &rhs);
    friend Vector3d cross(const Vector3d &lhs, const Vector3d &rhs);

    friend Vector3d operator+(double s, const Vector3d &rhs);
    friend Vector3d operator-(double s, const Vector3d &rhs);
    friend Vector3d operator*(double s, const Vector3d &rhs);

    friend std::ostream& operator<<(std::ostream &out, const Vector3d &v);
};
} // namespace raytrc

#endif // INCLUDE_BASE_VECTOR_3D_HPP