#include "./img/Img.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ImgTest
#include <boost/test/unit_test.hpp>

using namespace dotray::img;

BOOST_AUTO_TEST_CASE( get_set_pixel ) {
  Img<RGB_255> img(W(1920), H(1080));
  
  img.setPixel(W(0),H(0),0);
  BOOST_CHECK_EQUAL(img.getPixel(W(0), H(0)) , 0);
  
  img.setPixel(W(0),H(0),255);
  BOOST_CHECK_EQUAL(img.getPixel(W(0), H(0)) , 255);

  img.setPixel(W(1919),H(1079),127);
  BOOST_CHECK_EQUAL(img.getPixel(W(1919), H(1079)) , 127);
}

BOOST_AUTO_TEST_CASE( begin_end ) {
  Img<RGB_255> img(W(17), H(13));
  
  int c = 0;

  for (int h = 0 ; h < 13 ; ++h) {
    for (int w = 0 ; w < 17 ; ++w) {
      img.setPixel(W(w), H(h), (c%256));
      c++;
    }
  }

  c = 0;
  for (auto 
         it  = img.begin() ,
         end = img.end() ; it != end ; ++it){
    
    BOOST_CHECK_EQUAL(*it, (c%256));
    c++;
    
  }

}


















