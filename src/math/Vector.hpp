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
  Vector();
  Vector(const Vector &pointA, const Vector &pointB);
  Vector(const X x, const Y y, const Z z);
  X getX() const;
  Y getY() const;
  Z getZ() const;

  Scal norm() const;
  void normalize();
  Vector normalized() const;

};
                
const Scal operator*(const Vector & lhs, const Vector & rhs);
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
