#include <cmath>

#include "base/array_3d.hpp"

namespace raytrc {
Array3d& Array3d::operator+=(const Array3d &v) 
{
    mData[0] += v.mData[0];
    mData[1] += v.mData[1];
    mData[2] += v.mData[2];
    return *this;
}

Array3d& Array3d::operator*=(double s) 
{
    mData[0] *= s;
    mData[1] *= s;
    mData[2] *= s;
    return *this;
}

Array3d& Array3d::operator/=(double s) 
{
    return *this *= 1/s;
}

Array3d Array3d::operator+(const Array3d &rhs) const 
{
    return Array3d(mData[0] + rhs[0], mData[1] + rhs[1], mData[2] + rhs[2]);
}

Array3d Array3d::operator-(const Array3d &rhs) const 
{
    return Array3d(mData[0] - rhs[0], mData[1] - rhs[1], mData[2] - rhs[2]);
}

Array3d Array3d::operator*(const Array3d &rhs) const 
{
    return Array3d(mData[0] * rhs[0], mData[1] * rhs[1], mData[2] * rhs[2]);
}

Array3d Array3d::operator/(const double s) const 
{
    return Array3d(mData[0] / s, mData[1] / s, mData[2] / s);
}

Array3d operator+(double s, const Array3d &rhs) 
{
    return Array3d(s + rhs[0], s + rhs[1], s + rhs[2]);
}

Array3d operator-(double s, const Array3d &rhs) 
{
    return Array3d(s - rhs[0], s - rhs[1], s - rhs[2]);
}

Array3d operator*(double s, const Array3d &rhs) 
{
    return Array3d(s * rhs[0], s * rhs[1], s * rhs[2]);
}

std::ostream& operator<<(std::ostream &out, const Array3d &v) 
{
    return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

}
