/*
 * myException.cpp
 *
 *  Created on: May 27, 2010
 *      Author: damien
 */

#include "myException.h"

MyException::MyException(std::string name, int num)
{
	_name = name;
	_num = num;
}

MyException::~MyException() throw ()
{
}

const char* MyException::what() const throw ()
{
	return (_name.c_str());
}

int MyException::getNum() const
{
	return _num;
}
