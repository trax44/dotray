#include "./engine/Camera.hpp"
#include "./img/Img.hpp"
#include <iostream>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE CameraTest
#include <boost/test/unit_test.hpp>

using namespace dotray;
using namespace dotray::engine;

BOOST_AUTO_TEST_CASE( iterator ) {
  const Vector origine (X(0), Y(0), Z(0));
  Camera camera (origine, W(17), H(13), Scal(3), img::RGB_3_255);

  for (auto 
         it  = camera.begin(),
         end = camera.end() ; it != end ; ++it){
    
    if ((*it).getVect().getX() == 0 && 
        (*it).getVect().getY() == 0){
      
      BOOST_CHECK_EQUAL((*it).getVect().getZ(), 1);
      
    }
    
  }

}
