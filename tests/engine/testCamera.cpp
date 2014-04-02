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
  Camera camera (W(18), H(12), Scal(0), img::RGB_3_255);
  const Vector upper(X(6),Y(-9),Z(0));
  int i = 0;
  
  for (auto 
         it  = camera.begin(),
         end = camera.end() ; it != end ; ++it){
    Vector uv (X(-i/18),Y(uint32_t(i%18)), Z(0));
    Vector v = upper + uv;
    v.normalize();

    BOOST_CHECK_EQUAL(((*it).getVect() == (v+origin)), true);
    uv.print();
    v.print(); 
    (*it).getVect().print();
    std::cout << "--------------------------------------------------" << std::endl;
    ++i;
  }
}












