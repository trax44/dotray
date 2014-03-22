
include_directories(../src)


INCLUDE(Dart)


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

add_executable(CameraTest
engine/testCamera.cpp)
target_link_libraries (CameraTest
Shapes
Engine
${Boost_LIBRARIES})

add_test (imgTest imgTest) 
add_test (PGMTest PGMTest) 
add_test (VectorTest VectorTest)
add_test (PlanTest PlanTest)
add_test (CameraTest CameraTest)
