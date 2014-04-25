#ifndef		__ABONNEMENT_H__
#define		__ABONNEMENT_H__

#include <iostream>
#include <string>
#include <list>

#include "Client.h"

class			Abonnement
{
 private:
  std::list<Client *>	_abonnes;

 public:
  Abonnement();
  ~Abonnement();
 
  void			sabonner(Client *c);
  void			sedesabonner(Client *c);
  void			parution(std::string const &msg);
};

#endif		// __ABONNEMENT_H__
