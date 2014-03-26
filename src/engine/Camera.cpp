#include "Camera.hpp"

namespace dotray {

namespace engine {


Camera::Camera(const W w, const H h, const Scal depth,
               img::ImgType imgType) :
  vanishingPoint(X(0), Y(0), Z(0)),
  img(w,h),
  depth (depth),
  pointUpperCorner(X(h>>1), Y(-(w>>1)), Z(depth)),
  u(X(0),  Y(1), Z(0)),
  v(X(-1), Y(0), Z(0))
{}



} // engine

} // dotray










