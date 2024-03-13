#include "base/color.hpp"

namespace raytrc {

std::ostream& operator<<(std::ostream &os, const Color &c)
{
    os << static_cast<int>(255.999 * c.r()) << ' '
       << static_cast<int>(255.999 * c.g()) << ' '
       << static_cast<int>(255.999 * c.b()) << '\n';
    return os;
}

}
