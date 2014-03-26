#ifndef DOTRAY_ENGINE_ENGINE_H_
#define DOTRAY_ENGINE_ENGINE_H_

#include "shapes/Shape.hpp"
#include "Camera.hpp"

#include <list>
#include <memory>

namespace dotray {

namespace engine {

class Engine {
public:
  typedef std::list<shapes::Shape* > Shapes;

private:
  Camera &camera;
  Shapes &shapes;

  utils::Return<Scal> firstIntersection(const shapes::Line &line);

public:
  Engine(Camera &camera, Shapes &shapes);
  Camera &getCamera() const;
  ~Engine();
};

} // engine

} // dotray

#endif /* DOTRAY_ENGINE */
