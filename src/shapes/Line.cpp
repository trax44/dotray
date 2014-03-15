#include "Line.hpp"

namespace dotray {

namespace shapes {

Line::Line(const Vector &point, 
           const Vector &vect):
  point(point),
  vect(vect.normalized()){}

} // shapes

} // dotray
