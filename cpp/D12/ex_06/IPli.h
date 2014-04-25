#ifndef		__IPLI_H__
#define		__IPLI_H__

#include <iostream>
#include <string>

class		IPli
{
 public:
  IPli()
    {
    };
  virtual ~IPli() {};
  virtual void		pli() = 0;
};

#endif		// __IPLI_H__
