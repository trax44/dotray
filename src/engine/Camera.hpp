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
  shapes::Line lineCache;    

  void compute(){
    Y y(pixPosition%camera.img.getWidth());
    X x(int(pixPosition/camera.img.getWidth()));
    Z z(camera.depth);

    Vector vect (camera.u * y + 
                 camera.v * x + 
                 camera.pointUpperCorner);
    
    Vector v(camera.vanishingPoint, vect, true);
    lineCache = {camera.vanishingPoint, v};
    if (x != x){
      std::cout << std::endl;
      std::cout << this << " " << pixPosition << std::endl;
      std::cout << "PUC "; camera.pointUpperCorner.print();
      std::cout << "u   "; camera.u.print();
      std::cout << "v   "; camera.v.print();
      std::cout << "vect"; vect.print();
      std::cout << "x   " << x << " y " << y << std::endl;
      std::cout << "V   "; v.print();
      std::cout << "==============================" << std::endl;
    }
  }

public:
  iterator(Camera & camera, const uint32_t pixPosition):
    camera (camera),
    pixPosition(pixPosition){compute();}

  void operator=(const Color &color){
    camera.img.setPixel(pixPosition, color);
  }

  bool operator==(const iterator &a) {
    return (a.pixPosition == pixPosition);
  }

  bool operator!=(const iterator &a) {
    return (a.pixPosition != pixPosition);
  }
    
  

  void operator++(){
    ++pixPosition;
    compute();
  }

  const shapes::Line operator *() {
    return lineCache;
  }

};


private:
  math::Vector vanishingPoint;
  img::Img<img::RGB_3_255> img;
  const Scal depth;
  math::Vector pointUpperCorner;
  math::Vector u, v;

public:
  Camera(const W w, const H h, const Scal depth, 
         img::ImgType imgType);
  
  iterator begin(){
    return iterator (*this, 0);
  }

  iterator end(){
    return iterator (*this, img.getWidth() * img.getHeight());
  }

  img::Img<img::RGB_3_255> getImg() {
    return img;
  }  

};


} // engine

} // dotray

#endif /* DOTRAY_ENGINE */
