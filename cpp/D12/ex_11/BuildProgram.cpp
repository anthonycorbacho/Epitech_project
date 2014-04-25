#include "BuildProgram.h"

BuildProgram::BuildProgram(Builder *inst, void (Builder::*method)(int), int model)
{
  _builder = inst;
  _method = method;
  _model = model;
}

BuildProgram::~BuildProgram()
{
}

void		BuildProgram::execute()
{
  (_builder->*_method)(_model);
}
