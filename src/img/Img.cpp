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

void  Img<GREY_255>::setPixel (const uint32_t pixPosition, const Pixel t) {
  assert (static_cast<size_t>(pixPosition) <= data.size());
  data[pixPosition] = t;
}


Img<RGB_3_255>::Pixel Img<RGB_3_255>::getPixel (const W _w, const H _h) const {
  assert (static_cast<size_t>(PIX_POS(_w,_h)) <= data.size());
  return data[PIX_POS(_w, _h)];
}

void  Img<RGB_3_255>::setPixel (const W _w, const H _h, const Pixel t) {
  assert (static_cast<size_t>(PIX_POS(_w,_h)) <= data.size());
  data[PIX_POS(_w, _h)] = t;
}

void  Img<RGB_3_255>::setPixel (const uint32_t pixPosition, const Pixel t) {
  assert (static_cast<size_t>(pixPosition) <= data.size());
  data[pixPosition] = t;
}

} // img

} // dotray
