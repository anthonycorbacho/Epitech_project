//
// ex_4.hpp for ex_4 in /home/Anthony/Epitech/piscine/cpp/piscine/D10/ex_4
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May 13 00:24:13 2010 anthony1 corbacho
// Last update Thu May 13 19:59:45 2010 anthony1 corbacho
//

#ifndef __EX_4_H__
#define __EX_4_H__

#include <iostream>
#include <string>
#include <list>
#include <map>

template<typename K, typename V>
class		Pair
{
public:
  Pair() {}
  Pair(K key, V valeur)
  {
    _Key = key; 
    _Val= valeur;
  }
  
  Pair(const Pair &copy) 
  {
    _Key = copy._Key;
    _Val = copy._Val;
  }

  bool		operator==(const Pair &p)
  {
    if (_Key == p.getKey() && _Val == p.getValue())
      return 1;
    return 0;
  }

  Pair&		operator=(const Pair& copy)
  {
    if (this != &copy)
      {
	this->_Key = copy._Key;
	this->_Val = copy._Val;
      }
    return *this;
  }

  const K&		getKey() const
  {
    return this->_Key;
  }

  const V&		getValue() const
  {
    return this->_Val;
  }

private:
  K	_Key;
  V	_Val;
};

template <typename K, typename V>
class		Multimap
{
public:
  Multimap(){ }

  Multimap(K key, V val)
  {
    Pair<K, V> p(key, val);
    _liste.push_back(p);
  }

  Multimap(const Multimap& Map)
  {
    this->_liste = Map._liste;
  }

  Multimap&	operator=(const Multimap& Map)
  {
    if (this != &Map)
      {
	this->_liste = Map._liste;
      }
    return *this;
  }

  void		clear()
  {
    _liste.clear();
  }

  unsigned  long		count(const K& key)
  {

    unsigned long              tot = 0;
    typename std::list<Pair<K, V> >::iterator	debut = _liste.begin();
    typename std::list<Pair<K, V > >::iterator	fin = _liste.end();

    for (; debut != fin; ++debut)
      {
	if (key == debut->getKey())
	  tot++;
      }    
    return tot;
  }

  bool		empty() const
  {
    if (_liste.empty() == 1)
      return 1;
    return 0;
  }

  void		erase(const K& key)
  {

    typename std::list<Pair<K, V> >::iterator	debut = _liste.begin();
    typename std::list<Pair<K, V > >::iterator	fin = _liste.end();
    for ( ; debut != fin; ++debut)
      {
	if (key == debut->getKey())
	  _liste.erase(debut);
      }
  }

  void		erase(const Pair<K, V>& pair)
  {
    _liste.remove(pair);
  }

  const std::list< Pair<K, V> >* find(const K& key)
  {
    std::list< Pair<K, V> >* new_liste = new std::list< Pair<K, V> >();
    typename std::list<Pair<K, V> >::iterator	debut = _liste.begin();
    typename std::list<Pair<K, V > >::iterator	fin = _liste.end();
        
    for (; debut != fin; ++debut)
      {
	if (debut->getKey() == key)
	  {
	    Pair<K, V>	p(debut->getKey(), debut->getValue());
	    new_liste->push_back(p);
	  }
      }
      return new_liste;
  }

  void		insert(const K& key, const V& value)
  {
    Pair<K, V>	P(key, value);
    _liste.push_back(P);
  }
  
  void		insert(const Pair<K, V>& pair)
  {
    _liste.push_back(pair);
  }

  unsigned long size() const
  {
    return _liste.size();
  }

  void		swap(Multimap<K, V>& map)
  {
    _liste.swap(map._liste);
  }

private:
  std::list<Pair <K, V> >	_liste;
};

#endif /*__EX_4_H__*/
