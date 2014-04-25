#ifndef		__PROGRAM_H__
#define		__PROGRAM_H__

#include <iostream>
#include <string>
#include "Robot.h"

class			Program
{
 public:
  Program();

  virtual ~Program()
    {
    }

  virtual void		execute() = 0;
 private:

};
#endif		// __PROGRAM_H__
