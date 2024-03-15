#ifndef INCLUDE_BASE_ARRAY_3D_HPP
#define INCLUDE_BASE_ARRAY_3D_HPP

#include <iostream>
#include <concepts>
#include <type_traits>

namespace raytrc {
class Array3d {
protected:
    double mData[3];

public:

    Array3d() : mData{0, 0, 0} {}
    Array3d(double e0, double e1, double e2) : mData{e0, e1, e2} {}
    Array3d(const Array3d &array3d) : mData{array3d[0], array3d[1], array3d[2]} {}

    Array3d operator-() const 
    {
        return Array3d(-mData[0], -mData[1], -mData[2]);
    }

    double operator[](int i) const 
    {
        return mData[i];
    }

    double &operator[](int i)
    {
        return mData[i];
    }

    Array3d& operator+=(const Array3d &rhs)
    {
        mData[0] += rhs.mData[0];
        mData[1] += rhs.mData[1];
        mData[2] += rhs.mData[2];
        return *this;
    }

    Array3d& operator*=(double s)
    {
        mData[0] *= s;
        mData[1] *= s;
        mData[2] *= s;
        return *this;
    }

    Array3d& operator/=(double s)
    {
        return *this *= 1/s;
    }


    inline friend Array3d operator+(const Array3d &lhs, const Array3d &rhs)
    {
        return Array3d(lhs[0] + rhs[0], lhs[1] + rhs[1], lhs[2] + rhs[2]);
    }

    inline friend Array3d operator-(const Array3d &lhs, const Array3d &rhs)
    {
        return Array3d(lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2]);
    }

    inline friend Array3d operator*(const Array3d &lhs, const Array3d &rhs)
    {
        return Array3d(lhs[0] * rhs[0], lhs[1] * rhs[1], lhs[2] * rhs[2]);
    }

    inline friend Array3d operator/(const Array3d &lhs, const double s)
    {
        return Array3d(lhs[0] / s, lhs[1] / s, lhs[2] / s);
    }

    inline friend Array3d operator+(double s, const Array3d &rhs)
    {
        return Array3d(s + rhs[0], s + rhs[1], s + rhs[2]);
    }

    inline friend Array3d operator+(const Array3d &rhs, double s)
    {
        return s + rhs;
    }

    inline friend Array3d operator-(double s, const Array3d &rhs)
    {
        return Array3d(s - rhs[0], s - rhs[1], s - rhs[2]);
    }

    inline friend Array3d operator-(const Array3d &rhs, double s)
    {
        return -s + rhs;
    }

    inline friend Array3d operator*(double s, const Array3d &rhs)
    {
        return Array3d(s * rhs[0], s * rhs[1], s * rhs[2]);
    }

    inline friend Array3d operator*(const Array3d &rhs, double s)
    {
        return s * rhs;
    }

    inline friend std::ostream& operator<<(std::ostream &out, const Array3d &v)
    {
        return out << v[0] << ' ' << v[1] << ' ' << v[2];
    }

};


} // namespace raytrc

#endif // INCLUDE_BASE_ARRAY_3D_HPP