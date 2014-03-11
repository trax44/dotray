#include <cstdlib>
#include "img/PGM.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ImgTest
#include <boost/test/unit_test.hpp>

using namespace dotray::img;


BOOST_AUTO_TEST_CASE( PGM_img ) {
  Img<GREY_255> img(W(17), H(13));
  int c = 0;
  for (int h = 0 ; h < 13 ; ++h) {
    for (int w = 0 ; w < 17 ; ++w) {
      img.setPixel(W(w), H(h), (c%256));
      c++;
    }
  }

  BOOST_CHECK_EQUAL(PGM::save ("img.pgm", img), true);
  BOOST_CHECK_EQUAL(std::system ("md5sum -c img.md5"), 0);
}
