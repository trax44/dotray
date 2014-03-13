add_executable(imgTest
img/testImg.cpp)

add_executable(PGMTest
img/testPGM.cpp)

add_executable(VectorTest
math/testVector.cpp)

include_directories(../src)

target_link_libraries (imgTest
Img
${Boost_LIBRARIES})

target_link_libraries (PGMTest
Img
${Boost_LIBRARIES})

target_link_libraries (VectorTest
Math
${Boost_LIBRARIES})