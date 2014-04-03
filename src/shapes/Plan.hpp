#ifndef DOTRAY_SHAPE_PLAN_H_
#define DOTRAY_SHAPE_PLAN_H_

#include "Shape.hpp"
#include "math/Point.hpp"
#include "math/Vector.hpp"
using namespace dotray::math;

namespace dotray {

namespace shapes {

class Plan :public Shape {
private:
  const Point p;
  const Vector n;
  
public:

  Plan(const Point &a, 
       const Point &b,
       const Point &c);
  
  /**
   * \param p point of the plan
   * \param n normal vector to the plan
   */
  Plan(const Point &p, 
       const Vector &n);

  const utils::Return<Scal> getIntersection(const Line &line,
                                            Color *color) const;
  
};

} // shapes

} // dotray

#endif /* DOTRAY_SHAPE */
