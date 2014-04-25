/*
 * myException.h
 *
 *  Created on: May 27, 2010
 *      Author: damien
 */

#ifndef MYEXCEPTION_H_
#define MYEXCEPTION_H_

#include <exception>
#include <string>

class MyException: public std::exception
{

public:
	MyException(std::string name, int num = -1);
	~MyException() throw ();

	const char* what() const throw ();
	int getNum() const;

private:
	std::string _name;
	int _num;
};

#endif /* MYEXCEPTION_H_ */
