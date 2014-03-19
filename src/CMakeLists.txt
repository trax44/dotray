add_library(Img
img/Img.cpp
img/Img.hpp
img/PGM.cpp
img/PGM.hpp)
add_library(Math
math/Vector.cpp
math/Vector.hpp
math/Point.cpp
math/Point.hpp
math/Matrix.cpp
math/Matrix.hpp)

add_library(Math
math/Vector.cpp
math/Vector.hpp)

add_library(Shapes
shapes/Line.cpp
shapes/Line.hpp
shapes/Shape.hpp
shapes/Plan.cpp
shapes/Plan.hpp
)
target_link_libraries (Shapes
Math
)


include_directories(.)