add_executable(imgTest
img/testImg.cpp)

add_executable(PGMTest
img/testPGM.cpp)


include_directories(../src)

target_link_libraries (imgTest
Img
${Boost_LIBRARIES})

target_link_libraries (PGMTest
Img
${Boost_LIBRARIES})