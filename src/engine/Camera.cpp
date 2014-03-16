#include "Camera.hpp"

namespace dotray {

namespace engine {


Camera::Camera(const Vector &vanishingPoint, 
               const W w, const H h, const Scal depth,
               img::ImgType imgType) :
  vanishingPoint(vanishingPoint),
  img(w,h),
  depth (depth){}



} // engine

} // dotray










