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
    const shapes::Line line;
    iterator(Camera & camera, 
             const uint32_t pixPosition, 
             const Vector &vanishingPoint):
      camera (camera),
      pixPosition(pixPosition),
      line (vanishingPoint,
            {vanishingPoint, 
                {X(vanishingPoint.getX()-(camera.img.getWidth()/2)),
                    Y(vanishingPoint.getY()+(camera.img.getHeight()/2)),
                    Z(vanishingPoint.getZ() + camera.depth)}
            }) {}

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
      Y y(pixPosition/camera.img.getWidth());
      Z z(camera.depth);

      Vector lineVect(camera.vanishingPoint,
                      {X(x - (camera.img.getWidth()>>1)),  
                          Y((camera.img.getHeight()>>1) - y), 
                          Z(z + camera.vanishingPoint.getZ())});
      


      Vector v(camera.vanishingPoint, lineVect);
      shapes::Line line (camera.vanishingPoint, v);
      return line;

    }

  };


private:
  const Vector vanishingPoint;
  img::Img<img::RGB_3_255> img;
  const Scal depth;
  
public:
  Camera(const Vector &vanishingPoint, 
         const W w, const H h, const Scal depth, 
         img::ImgType imgType);

  iterator begin(){
    return iterator (*this, 0, vanishingPoint);
  }

  iterator end(){
    return iterator (*this, img.getWidth() * img.getHeight(), vanishingPoint);
  }

};


} // engine

} // dotray

#endif /* DOTRAY_ENGINE */
