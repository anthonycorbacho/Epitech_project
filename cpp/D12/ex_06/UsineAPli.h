#ifndef		__USINEAPLI_H__
#define		__USINEAPLI_H__

#include <iostream>
#include <string>
#include <map>

#include "IPli.h"
#include "TriplePliChinois.h"
#include "EcoPli.h"
#include "PliDemiLuneCerclee.h"

class UsineAPli
{
 private:
  typedef IPli* (UsineAPli::*fptr)() const;
  std::map<std::string, fptr>	_fptrs;
 public:
  UsineAPli();
  ~UsineAPli();
  IPli*	forgePli(std::string const &str);
  IPli*	forgePliDemiLuneCerclee() const;
  IPli*	forgeTriplePliChinois() const;
  IPli*	forgeEcoPli() const;
  void	learnPli(std::string const &, UsineAPli::fptr);
 
};

#endif		// __USINEAPLI_H__
