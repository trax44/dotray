#include "PGM.hpp"

namespace dotray {

namespace img {



bool PGM::save (const std::string &filename, const Img<GREY_255> &img) {
  std::ofstream myfile;
  myfile.open (filename);
  const bool res (myfile.is_open());
  if (!res){
    return false;
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

bool PGM::save (const std::string &filename, const Img<RGB_3_255> &img) {
  std::ofstream myfile;
  myfile.open (filename);
  const bool res (myfile.is_open());
  if (!res){
    return false;
  }

  myfile << "P3\n";
  myfile << std::to_string(img.getWidth()) << " " 
         << std::to_string(img.getHeight()) << "\n";

  myfile << "255\n";

  int pixCount = 0;
  for (auto 
         it  =  img.cbegin() ,
         end   = img.cend() ; it != end ; ++it){
    myfile << std::to_string (it->R) << " "
           << std::to_string (it->G) << " "
           << std::to_string (it->B) << "  ";
    ++pixCount;
    if ((pixCount % img.getWidth()) == 0){
      myfile << "\n";
    }
    
  }
  myfile << "\n";

  myfile.close();
  return true;

}

//   bool PGM::saveImg (const std::string &filename, 
// 		     Img<RGB_3_255>::const_iterator &begin,
// 		     Img<RGB_3_255>::const_iterator &end) {

    
  
// }


} // img

} // dotray
