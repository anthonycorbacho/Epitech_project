/*
 * main.cpp
 *
 *  Created on: Jun 11, 2010
 *      Author: matt
 */

#include "Factory.h"

#include "parsing.hpp"
#include "myException.h"
#include <iostream>
#include "VM.h"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./exe file" << std::endl;
		return 1;
	}
	std::string file = "analiser.txt";
	try
	{
		VM *vm = VM::getInstance(file);
		vm->run();
	} catch (MyException &e)
	{
		std::cout << "Exception catched: " << e.what() << std::endl;
	}
#ifdef _WIN32
	getchar();
#endif
	std::cout << "AbstractVm done..." << std::endl;
	return 0;
}
