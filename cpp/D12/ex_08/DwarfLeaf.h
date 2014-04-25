#ifndef		__DWARFLEAF_H__
#define		__DWARFLEAF_H__

#include <iostream>
#include <string>
#include <list>

#include "IDwarf.h"

class			DwarfLeaf : public IDwarf
{
 private:
  std::string		_name;
 public:
  DwarfLeaf(std::string const &name);
  ~DwarfLeaf();

  void			raler() const;
};

#endif		// __DWARFLEAF_H__
