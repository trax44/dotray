#ifndef DOTRAY_MATH_VECTOR_H_
#define DOTRAY_MATH_VECTOR_H_

#include "utils/commonTypes.hpp"

namespace dotray {
    namespace math {

class Vector {             
  X x;
  Y y;
  Z z;
public :
  Vector();
  Vector(const Vector &v);
  Vector(const Vector &va, 
         const Vector &vb, 
         const bool normalize = false);

  Vector(const X x, 
         const Y y, 
         const Z z, 
         const bool normalize = false);

  X getX() const;
  Y getY() const;
  Z getZ() const;

  Scal norm() const;
  void normalize();
  Vector normalized() const;
  void print() const;
};
                
const Scal operator*(const Vector & lhs, const Vector & rhs);
const Vector operator*(const int & lhs, const Vector & rhs);
const Vector operator*(const Vector & lhs, const int & rhs);
const Vector operator^(const Vector & lhs, const Vector & rhs);
const Vector operator+(const Vector & lhs, const Vector & rhs);

const Vector operator+(const Vector & lhs, const X x);
const Vector operator+(const Vector & lhs, const Y y);
const Vector operator+(const Vector & lhs, const Z x);

const Vector operator-(const Vector & lhs, const Vector & rhs);
const bool operator==(const Vector & lhs, const Vector & rhs);
} //math
} //dotray

#endif /* DOTRAY_MATH_VECTOR_H_ */
