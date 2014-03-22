#include "./engine/Camera.hpp"
#include "./img/Img.hpp"
#include <iostream>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE CameraTest
#include <boost/test/unit_test.hpp>

using namespace dotray;
using namespace dotray::engine;

BOOST_AUTO_TEST_CASE( iterator ) {
  const Vector origin (X(0), Y(0), Z(0));
  Camera camera (W(17), H(13), Scal(0), img::RGB_3_255);
  const Vector upper(X(8),Y(6),Z(0));
  int i = 0;
  
  for (auto 
         it  = camera.begin(),
         end = camera.end() ; it != end ; ++it){
    Vector uv (X(-i%17),Y(int(i/13)), Z(0));
    Vector v = upper + uv;
    

    BOOST_CHECK_EQUAL(((*it).getVect() == (v+origin)), true);
    std::cout << "**************************************************" << std::endl<< std::endl<< std::endl;

    ++i;
  }
}
