#include <cmath>
#include "Vector.hpp"

namespace dotray {
    namespace math {

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

        Scal Vector::norm() const{
            auto r = (x*x+y*y+z*z);
            return Scal(std::sqrt(r));
        }

        void Vector::normalize() {
            Scal d = norm();
            Scal t;
  

            if (d != Scal(0.0f)) {
                t= 1/d;
                x *= t;
                y *= t;
                z *= t;
            }
        }

        Vector Vector::normalized() const{
            Scal d = norm();
            Scal t;

            Vector v = *this;

            if (d != Scal(0)) {
                t= 1/d;
                v.x *= t;
                v.y *= t;
                v.z *= t;
            }

            return v;
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

    } //math
} //dotray
