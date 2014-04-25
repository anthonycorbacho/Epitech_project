//
// ex_2.hpp for ex_2 in /home/Anthony/Epitech/piscine/cpp/piscine/D10/ex_2
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Wed May 12 19:09:27 2010 anthony1 corbacho
// Last update Thu May 13 15:43:26 2010 anthony1 corbacho
//

#ifndef __EX_2_H__
#define __EX_2_H__
#include <string>
#include <iostream>

class	Ref
{
private:
  int	_nb;

public:
  void		AddRef() { ++_nb; }
  int		SetRef() { return --_nb;}  
};

template <typename T>
class		GC
{
public:
  GC(): _Pointeur(0), _Reference(0)
  {
    _Reference = new Ref();
    _Reference->AddRef();
  }

  GC(T *ref)
  {
    _Pointeur = ref;
    _Reference = new Ref();
    _Reference->AddRef();
  }

  ~GC()
  {
    if (_Reference->SetRef() == 0)
      {
	std::cout << "Destroying object" << std::endl;
	delete _Reference;
	delete _Pointeur;
      }
  };
  
  GC(const GC& copy)
  {
    _Reference = copy._Reference;
    _Pointeur = copy._Pointeur;
    //  _Reference->AddRef();
  };

  T&		operator*() { return *_Pointeur; };
    
  T*		operator->(){ return _Pointeur; };

  GC&		operator= (const GC& val)
  {
    if (this != &val)
      {
	_Pointeur = val._Pointeur;
	_Reference = val._Reference;
	_Reference->AddRef();
      }
    return *this;
  };

private:
  T*	_Pointeur;
  Ref*	_Reference;

};

#endif /*__EX_2_H__*/
