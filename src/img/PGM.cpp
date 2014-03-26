#include "PGM.hpp"

#include <algorithm>

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
 for (auto it  =  img.cbegin() , end = img.cend() ; 
      it != end ; ++it){
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

  float intensityMax = 0;
  float intensityMin = 65535;
  float minColor = 1;
  for(auto it = img.cbegin(), end = img.cend() ;
      it != end ; ++it) {
    intensityMax = std::max(it->intensity, intensityMax);
    intensityMin = std::min(it->intensity, intensityMin);
  }
  
  if (intensityMax == 0){
    intensityMax = 65535;
  }
  const float normalizeFactory (65535/(255*(intensityMax-intensityMin)));

  std::cout << "intensity range " << intensityMin 
            << " " << intensityMax 
            << " " << normalizeFactory 
            << " " << minColor
            << std::endl;

  myfile << "P3\n";
  myfile << std::to_string(img.getWidth()) << " " 
         << std::to_string(img.getHeight()) << "\n";

  myfile << "65535\n";

  int pixCount = 0;
  for (auto 
         it  =  img.cbegin() ,
         end   = img.cend() ; it != end ; ++it){
    myfile << std::to_string (int32_t((it->R*it->intensity - intensityMin)*normalizeFactory)) << " "
           << std::to_string (int32_t((it->G*it->intensity - intensityMin)*normalizeFactory)) << " "
           << std::to_string (int32_t((it->B*it->intensity - intensityMin)*normalizeFactory)) << "  ";
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
