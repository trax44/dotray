#ifndef DOTRAY_MATH_TRANSFORM_H_
#define DOTRAY_MATH_TRANSFORM_H_

#include "Vector.hpp"

namespace dotray {

namespace math {

class Transform {
public:
  typedef float angle;

  enum class Axe{
    X, Y, Z
  };
  
public:
  void rotX(const angle){}
  void rotY(const angle){}
  void rotZ(const angle){}

  void translate(const Vector &){}
  void scale(const Scal, const Axe){}

  void apply(Vector &v){}

};

} // math

} // dotray

#endif /* DOTRAY_MATH */










