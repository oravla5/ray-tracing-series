#ifndef INCLUDE_BASE_COLOR_HPP
#define INCLUDE_BASE_COLOR_HPP

#include "base/array_3d.hpp"

#include <iostream>

namespace raytrc {
class Color : public Array3d {
public:
    Color() : Array3d() {}
    Color(double r, double g, double b) : Array3d(r, g, b) {}
    Color(const Array3d &array3d) : Array3d(array3d) {}

    inline double r() const { return (*this)[0]; }
    inline double g() const { return (*this)[1]; }
    inline double b() const { return (*this)[2]; }

    friend std::ostream& operator<<(std::ostream &os, const Color &c);
};
}

#endif // INCLUDE_BASE_COLOR_HPP
