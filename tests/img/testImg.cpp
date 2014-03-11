#include "./img/Img.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ImgTest
#include <boost/test/unit_test.hpp>

using namespace dotray::img;

BOOST_AUTO_TEST_CASE( my_test ) {
  Img<RGB_255> img(W(1920), H(1080));
  
  img.setPixel(W(0),H(0),0);
  BOOST_CHECK_EQUAL(img.getPixel(W(0), H(0)) , 0);
  
  img.setPixel(W(0),H(0),255);
  BOOST_CHECK_EQUAL(img.getPixel(W(0), H(0)) , 255);

  img.setPixel(W(1919),H(1078),127);
  BOOST_CHECK_EQUAL(img.getPixel(W(1919), H(1078)) , 127);
}


















