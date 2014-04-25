#ifndef		__BUILDER_H__
#define		__BUILDER_H__

#include <iostream>
#include <string>

class			Builder
{
 public:
  Builder(std::string const &type);
  ~Builder();
  
  void			BuildCar(int model);
  
 private:
  std::string		_type;
};

#endif		// __BUILDER_H__
