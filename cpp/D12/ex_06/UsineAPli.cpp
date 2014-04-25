#include "UsineAPli.h"

UsineAPli::UsineAPli()
{
}

UsineAPli::~UsineAPli()
{
}

IPli*		UsineAPli::forgePli(std::string const &str)
{
  std::map<std::string, fptr>::iterator	it = _fptrs.begin();

  for (; it != _fptrs.end(); ++it)
    if (it->first == str)
      return ((this->*(_fptrs[str]))());
  return (NULL);
}

IPli*		UsineAPli::forgePliDemiLuneCerclee() const
{
  return (new PliDemiLuneCerclee);
}

IPli*		UsineAPli::forgeTriplePliChinois() const
{
  return (new TriplePliChinois);
}

IPli*		UsineAPli::forgeEcoPli() const
{
  return (new EcoPli);
}

void		UsineAPli::learnPli(std::string const &name, UsineAPli::fptr ptr)
{
  _fptrs[name] = ptr;
}
