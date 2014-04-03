#ifndef DOTRAY_MATH_POINT_H_
#define DOTRAY_MATH_POINT_H_

#include "utils/commonTypes.hpp"
#include "Vector.hpp"

namespace dotray {
    namespace math {

        class Point {             
            X x;
            Y y;
            Z z;
        public :
            Point(X x, Y y, Z z);
            ~Point();
            X getX() const;
            Y getY() const;
            Z getZ() const;
            operator Vector() const;
        };

    } //math
} //dotray

#endif /* DOTRAY_MATH_POINT_H_ */
