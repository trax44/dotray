#include "Vector.hpp"
namespace dotray {
namespace math {
namespace vector {

Vector::Vector() {};


Vector::Vector(const X x, 
               const Y y, 
               const Z z) : 
  x(x), y(y), z(z) {};

Vector::Vector(const Vector &pointA,
               const Vector &pointB):
  x(pointB.getX() - pointB.getX()),
  y(pointB.getY() - pointB.getY()),
  z(pointB.getZ() - pointB.getZ()){}
  

X Vector::getX() const {
  return x;
}

Y Vector::getY() const {
  return y;
}

Z Vector::getZ() const {
  return z;
}

const Scal operator*(const Vector & lhs, const Vector & rhs) {
  return 
    static_cast<Scal>(lhs.getX() * rhs.getX() + 
                      lhs.getY() * rhs.getY() + 
                      lhs.getZ() * rhs.getZ());
}
const Vector operator*(const int & lhs, const Vector & rhs) {
  return Vector(X(lhs*rhs.getX()), 
                Y(lhs*rhs.getY()), 
                Z(lhs*rhs.getZ()));
}
const Vector operator*(const Vector & lhs, const int & rhs) {
  return Vector(X(lhs.getX()*rhs), 
                Y(lhs.getY()*rhs), 
                Z(lhs.getZ()*rhs));
}
const Vector operator^(const Vector & lhs, const Vector & rhs) {
  return Vector(X(lhs.getY()*rhs.getZ()-lhs.getZ()*rhs.getY()), 
                Y(lhs.getZ()*rhs.getX()-lhs.getX()*rhs.getZ()), 
                Z(lhs.getX()*rhs.getY()-lhs.getY()*rhs.getX()));
}
const Vector operator+(const Vector & lhs, const Vector & rhs) {
  return Vector(X(lhs.getX()+rhs.getX()), 
                Y(lhs.getY()+rhs.getY()), 
                Z(lhs.getZ()+rhs.getZ()));
}
const Vector operator-(const Vector & lhs, const Vector & rhs) {
  return Vector(X(lhs.getX()-rhs.getX()), 
                Y(lhs.getY()-rhs.getY()), 
                Z(lhs.getZ()-rhs.getZ()));
}
const bool operator==(const Vector & lhs, const Vector & rhs) {
  return 
    lhs.getX() == rhs.getX() && 
    lhs.getY() == rhs.getY() && 
    lhs.getZ() == rhs.getZ(); 
}
} //vector
} //math
} //dotray
