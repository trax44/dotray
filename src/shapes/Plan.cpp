#include "Plan.hpp"
#include <iostream>

namespace dotray {

namespace shapes {


Plan::Plan(const Vector &a, 
           const Vector &b,
           const Vector &c) : 
  p(b),
  n(a^c) {}

Plan::Plan(const Vector &p, 
           const Vector &n) :
  p(p),
  n(n){}

const utils::Return<Scal> Plan::getIntersection(const Line &line,
                                                Color *color) const {
  
  Scal denumerator = line.getVect() * n;

  if (denumerator == 0){
    return false;
  }

  Scal numerator = (p - line.getP()) * n;
  Scal r = static_cast<Scal>(numerator/denumerator);

  return {((r > 0)?true:false), r};
}


} // shapes

} // dotray










