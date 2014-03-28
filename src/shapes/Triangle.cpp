#include "Triangle.hpp"

namespace dotray {

namespace shapes {

Triangle::Triangle(const Vector &pointA, 
                   const Vector &pointB, 
                   const Vector &pointC) : 
  a  (pointA),
  e0 (pointA, pointB),
  e1 (pointA, pointC)
{}
  
const utils::Return<Scal> Triangle::getIntersection(const Line &line,
                                                    Color *color) const {


  Vector pvec (line.getVect() ^ e1);
  Scal det = pvec * e0;

  if (det < Scal(0.001)) {
    return false;
  }

  Vector tvec (a, line.getP());
  Scal u = tvec * pvec;

  if (u < 0  || u > det){
    return false;
  }

  Vector qvec (tvec ^ e0);
  Scal v = line.getVect() * qvec;
  
  if (v < 0 || (u + v) > det){
    return false;
  }
  
  Scal t = e1 * qvec;

  Scal inv_det = Scal(1 / det);
  t *= inv_det;
  u *= inv_det;
  v *= inv_det;

  std::cout << "det " << det << " t " << t << " u " << u << " v " << v << std::endl;

  // if (det > -0.0001 && det < 0.0001) {
  //   std::cout << "det == 0" << std::endl;
  //   return false;
  // }

  // Scal inv_det = Scal(1 / det);
  // Vector tvec (a, line.getP());
  // Scal u = Scal((pvec * tvec) * inv_det);
  
  // if (u < Scal(0) || u > Scal(1)){
  //   std::cout << "det > 0 " << u << std::endl;
  //   return false;
  // }
  
  // Vector qvec (tvec ^ e0);
  // Scal v = Scal((line.getVect() * qvec) * inv_det);

  // if (v < 0 || (u + v) > 1) {
  //   std::cout << "det > 0 " << v << " " << u << std::endl;
  //   return false;
  // }

  // Scal t ((e1 * qvec) * inv_det);

  



  return {true, t};
}



} // shapes

} // dotray












