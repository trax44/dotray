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

#define DOTRAY_STRONG_TYPEDEF(T, D)                                     \
struct D                                                                \
  : boost::totally_ordered1<D , boost::totally_ordered2< D, T > > {     \
    T t;                                                                \
    explicit D(const T t_) : t(t_) {};                                  \
    D(){};                                                              \
    D(const D & t_) : t(t_.t){}                                         \
    D & operator=(const D & rhs) { t = rhs.t; return *this;}            \
    D & operator=(const T & rhs) { t = rhs; return *this;}              \
    operator const T & () const {return t; }                            \
    operator T & () { return t; }                                       \
};


DOTRAY_STRONG_TYPEDEF(uint16_t, W);
DOTRAY_STRONG_TYPEDEF(uint16_t, H);
DOTRAY_STRONG_TYPEDEF(float, X);
DOTRAY_STRONG_TYPEDEF(float, Y);
DOTRAY_STRONG_TYPEDEF(float, Z);
DOTRAY_STRONG_TYPEDEF(float, Scal);

#define Epsilon 0.001
inline bool operator== (X a, X b) {
  return ((a - b) < Epsilon);
}
inline bool operator== (Y a, Y b) {
  return ((a - b) < Epsilon);
}
inline bool operator== (Z a, Z b) {
  return ((a - b) < Epsilon);
}

struct Color {
  float r,g,b;
  float intensity;
};


#endif /* DOTARAY */













