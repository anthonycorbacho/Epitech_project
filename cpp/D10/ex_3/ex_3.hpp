//
// ex_3.hpp for ex_3 in /home/Anthony/Epitech/piscine/cpp/piscine/D10/ex_3
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Wed May 12 21:02:52 2010 anthony1 corbacho
// Last update Thu May 13 00:10:28 2010 anthony1 corbacho
//

#ifndef __EX_3_H__
#define __EX_3_H__

#include <string>
#include <typeinfo>
#include <iostream>
#include <list>

class   ServiceBase
{
public:
  virtual ~ServiceBase() {}
  virtual bool    Start() = 0;
  virtual bool    Stop() = 0;                                                                      
};

template<typename T>
class		Service : public ServiceBase
{
protected:
  Service()
  {
  }
virtual ~Service()
  {
  }
public:
  static T&	getInstance()
  {
    if (!_Instence)
      _Instence = new T();
    return *_Instence;
  }

  static void	deleteInstance()
  {
    delete _Instence;
    _Instence = 0;
  }

public:
  static T*		_Instence;
};

template<typename T>
T		*Service<T>::_Instence = 0;

class		Worker : public Service<Worker>
{
public:
  friend	class Service<Worker>;
private:
  Worker() { std::cout << "Constructing worker" << std::endl; };
  ~Worker() { std::cout << "Destroying worker" << std::endl; };
  
public:
  bool	Start()
  {
    std::cout << "Starting worker" << std::endl;
    return 1;
  };
  
  bool	Stop()
  {
    std::cout << "Stopping worker" << std::endl;
    return 1;
  };

  int	Work()
  {
    std::cout << "A very long computation" << std::endl;
    return 42;
  };
};

class		Printer : public Service<Printer>
{
public:
  friend	class Service<Printer>;
private:
   Printer() { std::cout << "Constructing printer" << std::endl; };
  virtual ~Printer() { std::cout << "Destroying printer" << std::endl; };

public:
  bool	Start()
  {
    std::cout << "Starting printer" << std::endl;
    return 1;
  };

  bool	Stop()
  {
    std::cout << "Stopping printer" << std::endl;
    return 1;
  };

  bool	Print(std::string file)
  {
    std::cout << "Printing file " << file << std::endl;
    return 1;
  };
};

class		ManagerService
{
public:
  void		addService(ServiceBase* service)
  {
    _liste.push_back(service);
  };

  void removeService(ServiceBase* service)
  {
    _liste.remove(service);
  };

  void StartAll()
  {
    std::list<ServiceBase*>::iterator	debut = _liste.begin();
    std::list<ServiceBase*>::iterator	fin = _liste.end();
    
    for (; debut != fin; ++debut)
      {
	(*debut)->Start();
      }
  };

  void StopAll()
  {
    std::list<ServiceBase*>::iterator	debut = _liste.begin();
    std::list<ServiceBase*>::iterator	fin = _liste.end();
    
    for (; debut != fin; ++debut)
      {
	(*debut)->Stop();
      }
  };

  template <typename T>
  T* getService()
  {
    std::list<ServiceBase*>::iterator debut = _liste.begin();
    std::list<ServiceBase*>::iterator fin = _liste.end();
    for (;debut != fin; ++debut)
      if (typeid(**debut) == typeid(T))
	{
	  T * ret = dynamic_cast<T*> (*debut);
	  return (ret);
	}
    return (0);
  }
  std::list<ServiceBase*>	_liste;
};
#endif /*__EX_3_H__*/
