#include "Abonnement.h"

Abonnement::Abonnement()
{
}

Abonnement::~Abonnement()
{
}

void			Abonnement::sabonner(Client *c)
{
  _abonnes.push_back(c);
}

void			Abonnement::sedesabonner(Client *c)
{
  std::list<Client *>::iterator	it = _abonnes.begin();
  std::list<Client *>::iterator	ite = _abonnes.end();

  for (; it != ite; ++it)
    if (*it == c)
      _abonnes.erase(it);
}

void			Abonnement::parution(std::string const &msg)
{
  std::list<Client *>::iterator	it = _abonnes.begin();
  std::list<Client *>::iterator	ite = _abonnes.end();

  for (; it != ite; ++it)
    (*it)->prevenir(msg);
}

