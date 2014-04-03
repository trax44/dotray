#include "Point.hpp"

namespace dotray {
    namespace math {

        Point::Point(X x, Y y, Z z) : x(x), y(y), z(z) {};
        Point::~Point() {};

        X Point::getX() const {
            return x;
        }

        Y Point::getY() const {
            return y;
        }

        Z Point::getZ() const {
            return z;
        }

        Point::operator Vector() const {
            return Vector(x,y,z);
        }

    } //math
} //dotray
