#ifndef DOTRAY_SHAPES_LINE_H_
#define DOTRAY_SHAPES_LINE_H_

#include "math/Vector.hpp"

using namespace dotray::math;

namespace dotray {

namespace shapes {

class Line {
private:
  Vector point;
  Vector vect;
public:
  Line(){}
  Line(const Line &line);
  void operator=(const Line &line);
  Line(const Vector &point, 
       const Vector &vect);
  
  const Vector & getP()const {return point;}
  const Vector & getVect() const {return vect;}
  void print() const;
  
};

} // shapes

} // dotray

#endif /* DOTRAY_SHAPES */
