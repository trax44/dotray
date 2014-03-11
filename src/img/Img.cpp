#include "Img.hpp"


namespace dotray {

namespace img {

Img<GREY_255>::Pixel Img<GREY_255>::getPixel (const W _w, const H _h) const {
  assert (static_cast<size_t>(PIX_POS(_w,_h)) <= data.size());
  return data[PIX_POS(_w, _h)];
}

void  Img<GREY_255>::setPixel (const W _w, const H _h, const Pixel t) {
  assert (static_cast<size_t>(PIX_POS(_w,_h)) <= data.size());
  data[PIX_POS(_w, _h)] = t;
}


Img<GREY_255>::iterator Img<GREY_255>::begin(){
  return data.begin();
}

Img<GREY_255>::iterator Img<GREY_255>::end(){
  return data.end();
}

Img<GREY_255>::const_iterator Img<GREY_255>::cbegin() const{
  return data.cbegin();
}

Img<GREY_255>::const_iterator Img<GREY_255>::cend() const{
  return data.cend();
}


} // img

} // dotray
