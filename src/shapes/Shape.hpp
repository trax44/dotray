#ifndef DOTRAY_SHAPES_SHAPE_H_
#define DOTRAY_SHAPES_SHAPE_H_

#include "math/Vector.hpp"
#include "utils/Return.hpp"
#include "Line.hpp"
#include "math/Transform.hpp"
#include <list>

namespace dotray {
namespace shapes {


class Shape {
public:
  typedef std::list<Shape*> Shapes;

private:
  Shapes shapes;

public:
  virtual const utils::Return<Scal> getIntersection(const Line &line,
                                                    Color *color) const = 0;

  void add (Shape *shape){
    shapes.push_back(shape);
  }
  
  void applyTransform (math::Transform &transform) {
    for (auto it = shapes.begin() , end = shapes.end();
         it != end ; ++it) {
      (*it)->applyTransform(transform);
    } 
  }
  
};

} // shapes

} // dotray

#endif /* DOTRAY_SHAPES */













