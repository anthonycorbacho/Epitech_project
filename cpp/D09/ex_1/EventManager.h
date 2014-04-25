/*
** EventManager.h for EventManager in /home/Anthony/Epitech/piscine/cpp/piscine/D09/ex_1
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue May 11 15:42:29 2010 anthony1 corbacho
** Last update Tue May 11 18:24:06 2010 anthony1 corbacho
*/

#ifndef __EVENTMANAGER_H__
#define __EVENTMANAGER_H__

#include <iostream>
#include <string>
#include <list>
//#include <algorithme>
#include "Event.h"

class		EventManager
{
  public:
  EventManager();
  ~EventManager();
  EventManager(EventManager &);
  EventManager&		operator=(EventManager &);
  bool			operator() (unsigned int);
  
  void                addEvent(const Event&);
  void                removeEventsAt(unsigned int);
  void                dumpEvents(void) const;
  void                dumpEventAt(unsigned int) const;
  void                addTime(unsigned int);
  // Ajoute une liste d'evenement a la liste courante. Attention aux
  // evenement invalides (t deja passe) et a l'ordre d'insertion :-)
  void                addEventList(std::list<Event>&);

 private:
  unsigned int		_CurentTime;
  std::list<Event>	_liste;
};

#endif /*__EVENTMANAGER_H__*/
