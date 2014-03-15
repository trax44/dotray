
include_directories(../src)

# img
add_executable(imgTest
img/testImg.cpp)
target_link_libraries (imgTest
Img
${Boost_LIBRARIES})

add_executable(PGMTest
img/testPGM.cpp)
target_link_libraries (PGMTest
Img
${Boost_LIBRARIES})


# vector
add_executable(VectorTest
math/testVector.cpp)

target_link_libraries (VectorTest
Math
${Boost_LIBRARIES})


# shapes
add_executable(PlanTest
shapes/testPlan.cpp)
target_link_libraries (PlanTest
Shapes
${Boost_LIBRARIES})
