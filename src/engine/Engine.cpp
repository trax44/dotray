#include "Engine.hpp"
#include "./img/PGM.hpp"

#include <iostream>

namespace dotray {

namespace engine {

Engine::Engine(Camera &camera, Shapes &shapes) : 
  camera(camera),
  shapes(shapes){
  Color colorPlan = {0.4, 0.4, 0.4, 1};
  Color background = {0,0,0,0};
  Color color;

  int black = 0;
  int grey = 0;
  
  for (auto 
         it  = camera.begin(),
         end = camera.end() ; it != end ; ++it){

    auto r = firstIntersection(*it);

    if (r.success){
      color = colorPlan;
      color.intensity = (r.data);
      std::cout << "intersectes " << r.data << std::endl;
      grey++;
    }else {
      color = background;
      black++;
    }
    it = color;
  }

  std::cout << "black " << black << " grey " << grey << std::endl;

  auto img = getCamera().getImg();
  img::PGM::save ("plop.pgm", img);
}

utils::Return<Scal> Engine::firstIntersection(const shapes::Line &line){
  Scal min = Scal(0); // negative length are behind the camera
  bool gotIntersection = false;

  for (Shapes::iterator
         it  = shapes.begin() , 
         end = shapes.end() ; it != end ; ++it){
    
    utils::Return<Scal> intersectionDist = (*it)->getIntersection(line, NULL);
    
    if (!intersectionDist.success){
      continue;
    }
    
    if (gotIntersection == false){
      min = intersectionDist.data;
      gotIntersection = true;
    } else {
      min = std::min (min, intersectionDist.data);
    }
  }

  return {gotIntersection, min};
}

Camera &Engine::getCamera() const {
  return camera;
}

Engine::~Engine() {
  for (auto it = shapes.begin() , end = shapes.end() ; it != end ; ++it){
    delete *it;
  }
}

} // engine

} // dotray

