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
