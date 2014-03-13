#ifndef DOTRAY_MATH_VECTOR_H_
#define DOTRAY_MATH_VECTOR_H_

#include "utils/commonTypes.hpp"

namespace dotray {
    namespace math {
        namespace vector {

            class Vector {             
                X x;
                Y y;
                Z z;
            public :
                Vector(X x, Y y, Z z);
                ~Vector();
                X getX() const;
                Y getY() const;
                Z getZ() const;
            };
                
            const int operator*(const Vector & lhs, const Vector & rhs);
            const Vector operator*(const int & lhs, const Vector & rhs);
            const Vector operator*(const Vector & lhs, const int & rhs);
            const Vector operator^(const Vector & lhs, const Vector & rhs);
            const Vector operator+(const Vector & lhs, const Vector & rhs);
            const Vector operator-(const Vector & lhs, const Vector & rhs);
            const bool operator==(const Vector & lhs, const Vector & rhs);
        } //vector
    } //math
} //dotray

#endif /* DOTRAY_MATH_VECTOR_H_ */