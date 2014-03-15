#ifndef DOTRAY_SHAPES_LINE_H_
#define DOTRAY_SHAPES_LINE_H_

#include "math/Vector.hpp"

using namespace dotray::math::vector;

namespace dotray {

namespace shapes {

class Line {
private:
  const Vector point;
  const Vector vect;
public:
  Line(const Vector &point, 
       const Vector &vect);
  
  const Vector & getP()const {return point;}
  const Vector & getVect() const {return vect;}
  
};

} // shapes

} // dotray

#endif /* DOTRAY_SHAPES */
