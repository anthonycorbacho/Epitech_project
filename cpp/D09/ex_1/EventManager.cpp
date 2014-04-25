//
// EventManager.cpp for EventManagement in /home/Anthony/Epitech/piscine/cpp/piscine/D09/ex_1
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Tue May 11 15:45:11 2010 anthony1 corbacho
// Last update Tue May 11 18:49:50 2010 anthony1 corbacho
//

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Event.h"
#include "EventManager.h"

bool		cmp(Event e1, Event e2)
{
  return (e1.getTime() < e2.getTime());
}


EventManager::EventManager()
{
  _liste = std::list<Event>();
  _CurentTime = 0;
}

EventManager::~EventManager()
{
}

EventManager::EventManager(EventManager& event)
{
  _liste = event._liste;
  _CurentTime = event._CurentTime;
}

EventManager&	EventManager::operator=(EventManager& event)
{
  if (this != &event)
    {
      this->_CurentTime = event._CurentTime;
      this->_liste = event._liste;
    }
  return (*this);
}

bool		EventManager::operator() (unsigned int t)
{
  return (this->_CurentTime == t);
}

bool		sort_cmp(Event a, Event b)
{
  if (a.getTime() < b.getTime())
    return 1;
  return 0;
}

void		EventManager::addEvent(const Event& event)
{
  if (event.getTime() > this->_CurentTime)
    {
      this->_liste.push_back(event);
      this->_liste.sort(cmp);
    }
}

void		EventManager::dumpEvents(void) const
{
  std::list<Event>::const_iterator begin;
  
  for (begin = _liste.begin(); begin != _liste.end(); ++begin)
    {
      std::cout << begin->getTime() << ": " << begin->getEvent() << std::endl;
    }
}



void		EventManager::removeEventsAt(unsigned int tmp)
{
    Event		ToRemove(tmp, "");
  
    this->_liste.remove(ToRemove);
}

void	       EventManager::dumpEventAt(unsigned int t) const
{
  std::list<Event>::const_iterator d;
  
  for (d = _liste.begin(); d != _liste.end(); ++d)
    {
      if (t == d->getTime())
	std::cout << d->getTime() << ": " << d->getEvent() << std::endl;
    }
}

void                EventManager::addTime(unsigned int t)
{
  std::list<Event>::const_iterator	ite; 
  
  this->_CurentTime += t;
  for (ite = _liste.begin(); ite != _liste.end(); ite++)
    {
      if (ite->getTime() <= _CurentTime)
	std::cout << ite->getEvent() << std::endl;
    }
  for (ite = _liste.begin(); ite != _liste.end(); ite++)
    {
      if (ite->getTime() <= _CurentTime)
	{
	  Event		e(ite->getTime(), "");
	  _liste.remove(e);
	}
    }
}

void		EventManager::addEventList(std::list<Event>& myListe)
{
  std::list<Event>::const_iterator	it;
  
  myListe.sort(cmp);
  for (it = myListe.begin(); it != myListe.end(); it++){
    if (it->getTime() > this->_CurentTime)
      {
	Event	e(it->getTime(), it->getEvent());
	addEvent(e);
      }
  }
}
