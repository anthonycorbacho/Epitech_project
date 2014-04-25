#include "Robot.h"

Robot::Robot(std::string const &name)
{
  _name = name;
}

Robot::~Robot()
{
}

void			Robot::addProgram(Program *p)
{
  _progs.push_back(p);
}

void			Robot::execPrograms()
{
  std::vector<Program *>::iterator	it = _progs.begin();
  std::vector<Program *>::iterator	ite = _progs.end();

  std::cout
    << "Booting "
    << _name
    << std::endl;
  for (; it != ite; ++it)
    (*it)->execute();
  std::cout
    << "Shutting Down"
    << std::endl;
}
