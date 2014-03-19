#include "Matrix.hpp"
#include <stdexcept>

namespace dotray {
    namespace math {

        Matrix::Matrix(const uint n, const uint m) : n(n), m(m), coeff(n*m,0) {};
        Matrix::~Matrix() {};

        const int Matrix::operator()(const uint & i, const uint & j) {
            if (i>=n) {
                throw std::out_of_range("The line in the matrix is out of range");
            }
            if (j>=m) {
                throw std::out_of_range("The column in the matrix out of range");
            }            
            return coeff[n*i+j];
        }

    } //math
} //dotray
