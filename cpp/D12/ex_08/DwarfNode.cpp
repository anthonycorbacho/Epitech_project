#include "DwarfNode.h"

DwarfNode::DwarfNode()
{
}

DwarfNode::~DwarfNode()
{
}

void		DwarfNode::raler() const
{
  std::list<IDwarf *>::const_iterator	it = _children.begin();
  std::list<IDwarf *>::const_iterator	ite = _children.end();
  for (; it != ite; ++it)
    (*it)->raler();
}

void		DwarfNode::addChild(IDwarf *d)
{
  _children.push_back(d);
}

