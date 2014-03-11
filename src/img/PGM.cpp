#include "PGM.hpp"

namespace dotray {

namespace img {

bool PGM::save (const std::string &filename, const Img<GREY_255> &img) {
  std::ofstream myfile;
  myfile.open (filename);
  const bool res (myfile.is_open());
  if (!res){
    return res;
  }
  


  myfile << "P2\n";
  myfile << std::to_string(img.getWidth()) << " " 
         << std::to_string(img.getHeight()) << "\n";

  myfile << "255\n";

  int pixCount = 0;
  for (auto 
         it  =  img.cbegin() ,
         end   = img.cend() ; it != end ; ++it){
    myfile << std::to_string (*it) << " ";
    ++pixCount;
    if ((pixCount % img.getWidth()) == 0){
      myfile << "\n";
    }
    
  }
  myfile << "\n";

  myfile.close();
  return true;

}

} // img

} // dotray
