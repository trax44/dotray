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
  const W w;
  const H h;

public:
  ImgTempl(const W w, const H h) : w(w), h(h){}
  virtual ~ImgTempl(){}

  virtual Pixel getPixel (const W, const H) const = 0;
  virtual void  setPixel (const W, const H, const Pixel) = 0;
};

template <int>
class Img;


template <>
class Img <RGB_255> : public ImgTempl <PixelTypeRGB_255>{
public:
  typedef PixelTypeRGB_255 Pixel;

private:
  typedef std::vector<Pixel> Data;
  Data data;

public:

  Img(const W w, const H h) : ImgTempl<PixelTypeRGB_255>(w, h),
                  data(h*(w+1)){}

  
  Pixel getPixel (const W, const H) const ;
  void  setPixel (const W w, const H h, const Pixel t);
};


Img<RGB_255>::Pixel Img<RGB_255>::getPixel (const W w, const H h) const {
  assert (static_cast<size_t>((h*(w+1))) <= data.size());
  return data[h*(w+1)];
}

void  Img<RGB_255>::setPixel (const W w, const H h, const Pixel t) {
  assert (static_cast<size_t>(h*(w+1)) <= data.size());
  data[h*(w+1)] = t;
}


} // img


} // dotray

#endif /* DOTRAY */










