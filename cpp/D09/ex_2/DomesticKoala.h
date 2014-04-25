/*
** DomesticKoala.h for DomesticKoala in /home/Anthony/Epitech/piscine/cpp/piscine/D09/ex_2
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue May 11 19:35:24 2010 anthony1 corbacho
** Last update Tue May 11 20:50:13 2010 anthony1 corbacho
*/

#ifndef __DOMESTICKOALA_H__
#define __DOMESTICKOALA_H__

#include <iostream>
#include <string>
#include <vector>
#include "KoalaAction.h"

class		DomesticKoala
{
 public:
  DomesticKoala(KoalaAction&);				// Constructeur principal
  ~DomesticKoala();                                     // Ca vous 
  DomesticKoala(const DomesticKoala&);                  // devez connaitre
  DomesticKoala&      operator=(const DomesticKoala&);  // a force... :-)

  typedef void (KoalaAction::*methodPointer_t)(const std::string &);
  // Permet de recuperer un vector contenant tous les pointeurs sur
  // methode
  std::vector<methodPointer_t> const *        getActions(void) const;
  // Assigne un pointeur sur methode, en liant le caractere (ordre),
  // au pointeur (action).
  void                learnAction(unsigned char, methodPointer_t);
  // Supprime l'ordre.
  void                unlearnAction(unsigned char);
  // Effectue l'action liee a l'ordre. La string est le parametre de 
  // la methode.
  void                doAction(unsigned char, const std::string&);
  // Affecte une nouvelle classe KoalaAction au koala domestique.
  // Cette action declenche une purge de la table de pointeur.
  void                setKoalaAction(KoalaAction&);

 private:
  KoalaAction				&_koala;
  std::vector<methodPointer_t>		_do;
  std::vector<char>			_ord;
};

#endif /*__DOMESTICKOALA_H__*/
