#include "Line.hpp"

namespace dotray {

namespace shapes {

Line::Line(const Line &line) : 
  point(line.getP()),
  vect(line.getVect()){}

void Line::operator=(const Line &line) {
  point = line.getP();
  vect  = line.getVect();
}

Line::Line(const Vector &point, 
           const Vector &vect):
  point(point),
  vect(vect.normalized()){}

void Line::print() const{
  std::cout << "line> p "; point.print(); 
  std::cout << "line> v "; vect.print(); 
}

} // shapes

} // dotray





