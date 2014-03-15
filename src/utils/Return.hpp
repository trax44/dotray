#ifndef DOTRAY_UTILS_RETURN_H_
#define DOTRAY_UTILS_RETURN_H_

namespace dotray {

namespace utils {


template <class T>
class Return {

public:
  T data;
  bool success;

  Return (bool _success):
    success(_success) {
  }
  
  Return (bool _success, T _data): 
    data(_data),
    success(_success) {
  }

  Return (T _data): 
    data(_data),
    success(true) {
  }

  template<typename CurrentType>
  Return (const Return <CurrentType> &r){
    data     = r.data;
    success  = r.success;
  }

  template<typename CurrentType>
  Return (Return <CurrentType> &r){
    data     = r.data;
    success  = r.success;
  }

};

template<>
class Return < void > {

public:
  bool success;

  Return (bool _success):
    success (_success){
  }
};


} // utils

} // dotray

#endif /* DOTRAY_UTILS */
