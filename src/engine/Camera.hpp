#ifndef DOTRAY_ENGINE_CAMERA_H_
#define DOTRAY_ENGINE_CAMERA_H_

#include "utils/commonTypes.hpp"
#include "math/Vector.hpp"
#include "img/Img.hpp"
#include "shapes/Line.hpp"
namespace dotray {

namespace engine {

class Camera {
public:

struct iterator {
private:
Camera  &camera;
  uint32_t pixPosition;
    
public:
  iterator(Camera & camera, const uint32_t pixPosition):
    camera (camera),
    pixPosition(pixPosition){}

  bool operator==(const iterator &a) {
    return (a.pixPosition == pixPosition);
  }

  bool operator!=(const iterator &a) {
    return (a.pixPosition != pixPosition);
  }
    
  void operator++(){
    ++pixPosition;
  }

  const shapes::Line operator *() {
    X x(pixPosition%camera.img.getWidth());
    Y y(int(pixPosition/camera.img.getHeight()));
    Z z(camera.depth);

    Vector vect (camera.u * y + 
                 camera.v * x + 
                 camera.pointUpperCorner);

    

    Vector lineVect(camera.vanishingPoint, vect, true);
      
    Vector v(camera.vanishingPoint, lineVect);

    shapes::Line line (camera.vanishingPoint, v);

    return line;
  }

};


private:
  math::vector::Vector vanishingPoint;
  img::Img<img::RGB_3_255> img;
  const Scal depth;
  math::vector::Vector pointUpperCorner;
  math::vector::Vector u, v;

public:
  Camera(const W w, const H h, const Scal depth, 
         img::ImgType imgType);
  
  iterator begin(){
    return iterator (*this, 0);
  }

  iterator end(){
    return iterator (*this, img.getWidth() * img.getHeight());
  }

};


} // engine

} // dotray

#endif /* DOTRAY_ENGINE */
