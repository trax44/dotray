#ifndef DOTARAY_COMMONTYPES_H_
#define DOTARAY_COMMONTYPES_H_

#include <cstdint>
#include <iostream>
#include <cassert>
#include <boost/serialization/strong_typedef.hpp>

using std::uint64_t;
using std::uint32_t;
using std::uint16_t;
using std::uint8_t;

using std::int64_t;
using std::int32_t;
using std::int16_t;
using std::int8_t;

BOOST_STRONG_TYPEDEF(uint16_t, W);
BOOST_STRONG_TYPEDEF(uint16_t, H);
BOOST_STRONG_TYPEDEF(float, X);
BOOST_STRONG_TYPEDEF(float, Y);
BOOST_STRONG_TYPEDEF(float, Z);
BOOST_STRONG_TYPEDEF(float, Scal);

#define Epsilon 0.001
inline bool operator== (X a, X b) {
  bool r;
  
  r =  ((a - b) < Epsilon);
  std::cout << "operator== " << a << " " << b << ((r)?" true ":" false ") << a-b << std::endl;

  return r;
}


inline bool operator== (Y a, Y b) {
  bool r;
  
  r =  ((a - b) < Epsilon);
  std::cout << "operator== " << a << " " << b << ((r)?" true ":" false ") << a-b << std::endl;

  return r;
}
inline bool operator== (Z a, Z b) {
  bool r;
  
  r =  ((a - b) < Epsilon);
  std::cout << "operator== " << a << " " << b << ((r)?" true ":" false ") << a-b << std::endl;

  return r;
}

struct Color {
  uint8_t r,g,b;
};


#endif /* DOTARAY */













