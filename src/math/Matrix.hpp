#ifndef DOTRAY_MATH_MATRIX_H_
#define DOTRAY_MATH_MATRIX_H_

#include <vector>
#include "utils/commonTypes.hpp"

namespace dotray {
    namespace math {

        class Matrix {
            const uint n;
            const uint m;
            std::vector<int> coeff;
        public :
            Matrix(const uint n, const uint m);
            ~Matrix();
            const int operator()(const uint & i, const uint & j);
        };
               
    } //math
} //dotray

#endif /* DOTRAY_MATH_MATRIX_H_ */
