#include <cstdlib>
#include "math/Vector.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE VectorTest
#include <boost/test/unit_test.hpp>

using namespace dotray::math::vector;



BOOST_AUTO_TEST_CASE( Equal ) {
  BOOST_CHECK_EQUAL(false, Vector(X(520),Y(26),Z(89))==Vector(X(26),Y(520),Z(89)));
  BOOST_CHECK_EQUAL(true, Vector(X(520),Y(26),Z(89))==Vector(X(520),Y(26),Z(89)));
}

BOOST_AUTO_TEST_CASE( Addition ) {

  Vector va(X(10),Y(2),Z(30)),vb(X(1),Y(2),Z(3));
  Vector vr = va + vb;
  BOOST_CHECK_EQUAL(true, Vector(X(11),Y(4),Z(33))==vr);
}

BOOST_AUTO_TEST_CASE( norm ) {

  Vector v0(X(0),Y(2),Z(0));
      
  BOOST_CHECK_EQUAL(v0.norm(), 2);

  Vector v1(X(0),Y(1),Z(0));
  BOOST_CHECK_EQUAL(v1.norm(), 1);
}


BOOST_AUTO_TEST_CASE( normlize ) {

  Vector v0(X(1),Y(2),Z(3));
  v0.normalize();
  auto r = v0.norm();
  
  BOOST_CHECK_LT(std::abs(r - 1), 0.001);
}










