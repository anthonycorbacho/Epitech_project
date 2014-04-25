#ifndef		__DWARFNODE_H__
#define		__DWARFNODE_H__

#include <iostream>
#include <string>
#include <list>

#include "IDwarf.h"

class			DwarfNode : public IDwarf
{
 private:
  std::list<IDwarf *>	_children;

 public:
  DwarfNode();
  ~DwarfNode();

  void			addChild(IDwarf *d);
  void			raler() const;
};

#endif		// __DWARFNODE_H__
