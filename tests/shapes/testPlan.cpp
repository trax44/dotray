#include "shapes/Plan.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ImgTest
#include <boost/test/unit_test.hpp>

using namespace dotray;
using namespace dotray::shapes;


BOOST_AUTO_TEST_CASE( Plan_intersection ) {
  const X x0(0); const Y y0(0); const Z z0(0);
  const X x1(1); const Y y1(1); const Z z1(1);

  
  Plan p  ({x0, y0, z1}, {x0, y0, Z(-z1)});
  Line d0 ({x1, y1, z1}, {x0, y1, z0});// // to the plan, no intersection
  Line d1 ({x0, y0, z0}, {x0, y1, z0});// // into the plan
  Line d2 ({x1, y0, z0}, {x0, y0, z1});// one point intersection
  Line d3 ({x0, y0, z0}, {x0, y0, z1});// one point intersection
  

  utils::Return<Scal> r0 = p.getIntersection(d0, NULL);
  utils::Return<Scal> r1 = p.getIntersection(d1, NULL);
  utils::Return<Scal> r2 = p.getIntersection(d2, NULL);
  utils::Return<Scal> r3 = p.getIntersection(d3, NULL);

  BOOST_CHECK_EQUAL (r0.success , false);

  BOOST_CHECK_EQUAL (r1.success , false);

  BOOST_CHECK_EQUAL (r2.success , true);
  BOOST_CHECK_EQUAL (r2.data    , 1);

  BOOST_CHECK_EQUAL (r3.success , true);
  BOOST_CHECK_EQUAL (r3.data    , 1);
  
}
