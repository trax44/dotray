#include "./img/Img.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ImgTest
#include <boost/test/unit_test.hpp>

using namespace dotray::img;

BOOST_AUTO_TEST_CASE( my_test ) {
  Img<RGB_255> img(W(1920), H(1080));

  BOOST_CHECK(img.getPixel(W(1920), H(1080)) == 0);
}











