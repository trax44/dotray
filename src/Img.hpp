#ifndef DOTRAY_IMG_IMG_H_
#define DOTRAY_IMG_IMG_H_


#include <vector>
#include "utils/commonTypes.hpp"


namespace dotray {

namespace img {

class Img {
public:
  enum class Type {
    BLACK_WHITE,
      RGB_255,
      RGB_3_255
      };

private:
  W w;
  H h;
  Type type;

public:
  Img(W w, H h, Type t);

  virtual ~Img(){}
};

} // img


} // dotray

#endif /* DOTRAY */










