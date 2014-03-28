#ifndef DOTRAY_SHAPES_TRIANGLE_H_
#define DOTRAY_SHAPES_TRIANGLE_H_

#include "Shape.hpp"

namespace dotray {

namespace shapes {

class Triangle : public Shape{
private:
  mutable Vector a;
  mutable Vector e0;
  mutable Vector e1;

public:
  Triangle(const Vector &pointA, 
           const Vector &pointB, 
           const Vector &pointC);

  const utils::Return<Scal> getIntersection(const Line &line,
                                            Color *color) const;
};

} // shapes

} // dotray

#endif /* DOTRAY_SHAPES */
