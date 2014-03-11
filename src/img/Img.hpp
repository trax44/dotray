#ifndef DOTRAY_IMG_IMG_H_
#define DOTRAY_IMG_IMG_H_


#include <vector>
#include "utils/commonTypes.hpp"

namespace dotray {

namespace img {

typedef uint8_t PixelTypeGREY_255;

enum ImgType {
  BLACK_WHITE = 1,
  GREY_255 = 2,
  RGB_3_255 = 3
};

#define PIX_POS(_W,_H) ((_W + w*_H))

template <typename Pixel, class MyContainer>
class ImgTempl {
public:
  typedef MyContainer Data;
  typedef typename MyContainer::iterator iterator;
  typedef typename MyContainer::const_iterator const_iterator;
  
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
  virtual iterator end  () = 0;

  virtual const_iterator cbegin() const = 0;
  virtual const_iterator cend  () const = 0;

};

template <int>
class Img;


template <>
class Img <GREY_255> : public ImgTempl <PixelTypeGREY_255, 
                                       std::vector<PixelTypeGREY_255> >{
public:
  typedef PixelTypeGREY_255 Pixel;

public:
  
  Img(const W w, const H h) : ImgTempl<PixelTypeGREY_255, Data>(w, h) {
    data.resize(w*h);
  }

  
  Pixel getPixel (const W, const H) const ;
  void  setPixel (const W w, const H h, const Pixel t);

  iterator begin();
  iterator end();
  
  const_iterator cbegin ()const;
  const_iterator cend   ()const;
  
};



} // img


} // dotray

#endif /* DOTRAY */



