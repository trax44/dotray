#ifndef DOTRAY_SHAPES_SHAPE_H_
#define DOTRAY_SHAPES_SHAPE_H_

#include "math/Vector.hpp"
#include "utils/Return.hpp"
#include "Line.hpp"

namespace dotray {
namespace shapes {

class Shape {
public:
  virtual const utils::Return<Scal> getIntersection(const Line &line,
                                                    Color *color) const = 0;
};

} // shapes

} // dotray

#endif /* DOTRAY_SHAPES */













