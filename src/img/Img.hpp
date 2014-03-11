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

#define PIX_POS(_W,_H) ((_W + w*_H))

template <typename Pixel, class MyContainer>
class ImgTempl {
public:
  typedef MyContainer Data;
  typedef typename MyContainer::iterator iterator;
  
protected:
  const W w;
  const H h;

  MyContainer data;

public:
  ImgTempl(const W w, const H h) : w(w), h(h){}
  virtual ~ImgTempl(){}

  const W getWidth() const {return w;}
  const H getHeight() const {return h;}

  virtual Pixel getPixel (const W, const H) const = 0;
  virtual void  setPixel (const W, const H, const Pixel) = 0;

  virtual iterator begin() = 0;
  virtual iterator end() = 0;

};

template <int>
class Img;


template <>
class Img <RGB_255> : public ImgTempl <PixelTypeRGB_255, 
                                       std::vector<PixelTypeRGB_255> >{
public:
  typedef PixelTypeRGB_255 Pixel;

public:
  
  Img(const W w, const H h) : ImgTempl<PixelTypeRGB_255, Data>(w, h) {
    data.resize(w*h);
  }

  
  Pixel getPixel (const W, const H) const ;
  void  setPixel (const W w, const H h, const Pixel t);

  iterator begin();
  iterator end();
  
};


Img<RGB_255>::Pixel Img<RGB_255>::getPixel (const W _w, const H _h) const {
  assert (static_cast<size_t>(PIX_POS(_w,_h)) <= data.size());
  return data[PIX_POS(_w, _h)];
}

void  Img<RGB_255>::setPixel (const W _w, const H _h, const Pixel t) {
  assert (static_cast<size_t>(PIX_POS(_w,_h)) <= data.size());
  data[PIX_POS(_w, _h)] = t;
}


Img<RGB_255>::iterator Img<RGB_255>::begin(){
  return data.begin();
}

Img<RGB_255>::iterator Img<RGB_255>::end(){
  return data.end();
}

} // img


} // dotray

#endif /* DOTRAY */



