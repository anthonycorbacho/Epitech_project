//
// ex_0.hpp for ex_0 in /home/Anthony/Epitech/piscine/cpp/piscine/D10/ex_0
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Wed May 12 12:38:26 2010 anthony1 corbacho
// Last update Wed May 12 13:27:14 2010 anthony1 corbacho
//

#ifndef __EX_0_H__
#define __EX_0_H__

#include <iostream>

class		IntModifier
{
public:
  void print(const int& data) {std::cout << data << std::endl;}
  void modify(int& data) {data++;}
};

class		FloatModifier
{
public:
  void print(const float& data) {std::cout << data << std::endl;}
  void modify(float& data) {data += 0.2;}
};

template <typename T>
class		Callback
{
public:
  Callback(T& data) : _Data(data) {}
  template <typename U>
  void	print(U& data, void (U::*fct)(const T& _Data)) const {(data.*fct)(_Data);}
  template <typename U>
  void	modify(U& data, void (U::*fct)(T& _Data)) {(data.*fct)(_Data);}
  template <typename U>
  void	print(U* data, void (U::*fct)(const T& _Data)) const {(data->*fct)(_Data);}
  template <typename U>
  void	modify(U* data, void (U::*fct)(T& _Data)) {(data->*fct)(_Data);}
private:
  T&		_Data;
};

#endif /*__EX_0_H__*/
