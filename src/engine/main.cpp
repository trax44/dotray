#include <iostream>
#include "engine/Engine.hpp"
#include "shapes/Plan.hpp"
#include "shapes/Triangle.hpp"
#include "engine/Camera.hpp"

using namespace dotray;

int main (int argc, char *argv[]){
  
  math::Vector origin (X(0), Y(0), Z(0));
  math::Vector direction (X(0), Y(0), Z(1));

  engine::Camera camera(W(640), H(480), Scal(100),
                        img::RGB_3_255);

  engine::Engine::Shapes shapes;
  
  const math::Point a(X(-300), Y(0), Z(0));
  const math::Vector n(X(1), Y(0), Z(0));
  // const math::Vector a(X(0), Y(0), Z(30));
  // const math::Vector n(X(0), Y(0), Z(-1));
  auto plan = new shapes::Plan (a, n);


  const math::Vector v0(X(0),   Y(0),   Z(200));
  const math::Vector v1(X(100), Y(0),   Z(200));
  const math::Vector v2(X(0),   Y(100), Z(200));
  
  //auto triangle = new shapes::Triangle(v1, v0, v2);

  // NO auto triangle = new shapes::Triangle(v0, v1, v2);
  // square auto triangle = new shapes::Triangle(v0, v2, v1);
  auto triangle = new shapes::Triangle(v1, v0, v2);
  // NO auto triangle = new shapes::Triangle(v1, v2, v0);
  // auto triangle = new shapes::Triangle(v2, v1, v0);
  // NO auto triangle = new shapes::Triangle(v2, v0, v1);

  //shapes.push_back(plan);
  shapes.push_back(triangle);
  
  engine::Engine engine(camera, shapes);
  
  
  return 0;
}







