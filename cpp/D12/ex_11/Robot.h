#ifndef		__ROBOT_H__
#define		__ROBOT_H__

#include <iostream>
#include <string>
#include <vector>

#include "Program.h"

class Program;

class			Robot
{

 public:
  Robot(std::string const &name);
  ~Robot();
  void			addProgram(Program *p);
  void			execPrograms();
  
 private:
  std::string			_name;
  std::vector<Program *>	_progs;
};

#endif		// __ROBOT_H__
