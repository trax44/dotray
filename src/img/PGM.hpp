#ifndef DOTRAY_IMG_PGM_H_
#define DOTRAY_IMG_PGM_H_


#include <iostream>
#include <fstream>
#include <string>

#include "Img.hpp"

namespace dotray {

namespace img {

class PGM {
public:
  static bool save (const std::string &filename, const Img<GREY_255> &img);
  static bool save (const std::string &filename, const Img<RGB_3_255> &img);
};


} // img

} // dotray
#endif /* DOTRAY_IMG */

