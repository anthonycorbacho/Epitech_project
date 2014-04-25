#ifndef		__BUILDPROGRAM_H__
#define		__BUILDPROGRAM_H__

#include <iostream>
#include <string>
#include "Builder.h"
#include "Program.h"

class			BuildProgram : public Program
{

 public:
  BuildProgram(Builder *inst, void (Builder::*method)(int), int model);
  ~BuildProgram();
  void			execute();
 
 private:
  Builder		*_builder;
  void			(Builder::*_method)(int);
  int			_model;
};

#endif		// __BUILDPROGRAM_H__
