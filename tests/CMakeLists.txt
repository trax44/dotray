add_executable(imgTest
img/testImg.cpp)


include_directories(../src)

target_link_libraries (imgTest
${Boost_LIBRARIES})