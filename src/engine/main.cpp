#include <iostream>
#include "engine/Engine.hpp"
#include "shapes/Plan.hpp"
#include "engine/Camera.hpp"

using namespace dotray;

int main (int argc, char *argv[]){
  
  math::Vector origin (X(0), Y(0), Z(0));
  math::Vector direction (X(0), Y(0), Z(1));

  engine::Camera camera(W(640), H(480), Scal(100),
                        img::RGB_3_255);

  engine::Engine::Shapes shapes;
  
  // const math::Vector a(X(-300), Y(0), Z(0));
  // const math::Vector n(X(1), Y(0), Z(0));
  const math::Vector a(X(0), Y(0), Z(30));
  const math::Vector n(X(0), Y(0), Z(-1));
 
  shapes.push_back(new shapes::Plan (a, n));
  
  engine::Engine engine(camera, shapes);
  
  
  return 0;
}
