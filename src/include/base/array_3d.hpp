#ifndef INCLUDE_BASE_ARRAY_3D_HPP
#define INCLUDE_BASE_ARRAY_3D_HPP

#include <iostream>

namespace raytrc {
class Array3d {
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

    Array3d& operator+=(const Array3d &rhs);
    Array3d& operator*=(double s);
    Array3d& operator/=(double t);

    Array3d operator+(const Array3d &rhs) const;
    Array3d operator-(const Array3d &rhs) const;
    Array3d operator*(const Array3d &rhs) const;
    Array3d operator/(const double s) const;

    friend Array3d operator+(double s, const Array3d &rhs);
    friend Array3d operator-(double s, const Array3d &rhs);
    friend Array3d operator*(double s, const Array3d &rhs);

    friend std::ostream& operator<<(std::ostream &out, const Array3d &v);

protected:
    double mData[3];
};
}

#endif // INCLUDE_BASE_ARRAY_3D_HPP