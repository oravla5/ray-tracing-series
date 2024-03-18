#ifndef INCLUDE_BASE_MATH_HPP
#define INCLUDE_BASE_MATH_HPP

#include <limits>
#include <math.h>

namespace raytrc {

// Constants
const double INFNTY = std::numeric_limits<double>::infinity();
const double PI = M_PI;

inline double deg2rad(double deg)
{
    return deg * PI / 180.0;
}

class Range {
public:
    Range() : mMin(+INFNTY), mMax(-INFNTY) {}
    Range(double min, double max) : mMin(min), mMax(max) {}

    double min() const 
    {
        return mMin;
    }

    double max() const
    {
        return mMax;
    }

    bool contains(double x) const
    {
        return (x >= mMin) && (x <= mMax);
    }

    bool surrounds(double x) const
    {
        return (mMin < x) && (x < mMax);
    }

    static const Range Empty, Universe;

private:
    double mMin;
    double mMax;
};

const static Range Empty (+INFNTY, -INFNTY);
const static Range Universe (-INFNTY, +INFNTY);

} // namespace raytrc

#endif // INCLUDE_BASE_MATH_HPP