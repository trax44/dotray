#ifndef DOTRAY_IMG_IMG_H_
#define DOTRAY_IMG_IMG_H_


#include <vector>
#include "utils/commonTypes.hpp"


namespace dotray {

namespace img {

typedef uint8_t PixelTypeRGB_255;

enum ImgType {
  BLACK_WHITE = 1,
  RGB_255 = 2,
  RGB_3_255 = 3
};



template <typename Pixel>
class ImgTempl {
private:
  W w;
  H h;

public:
  ImgTempl(const W w, const H h) : w(w), h(h){}
  virtual ~ImgTempl(){}

  virtual Pixel getPixel (const W, const H) = 0;
  virtual void  setPixel (const W, const H, const Pixel) = 0;
};

template <int>
class Img;


template <>
class Img <RGB_255> : public ImgTempl <PixelTypeRGB_255>{
public:
  typedef PixelTypeRGB_255 Pixel;
public:

  Img(W w, H h) : ImgTempl<PixelTypeRGB_255>(w, h){}

  
  Pixel getPixel (const W, const H);
  void  setPixel (const W w, const H h, const Pixel t);
};


Img<RGB_255>::Pixel Img<RGB_255>::getPixel (const W, const H) {
  return 0;
}
void  Img<RGB_255>::setPixel (const W w, const H h, const Pixel t) {
  
}


} // img


} // dotray

#endif /* DOTRAY */










