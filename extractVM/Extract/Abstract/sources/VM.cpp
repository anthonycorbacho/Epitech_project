/*
 * VM.cpp
 *
 *  Created on: Jun 12, 2010
 *      Author: matt
 */

#include "VM.h"
#include <iostream>
#include "myException.h"

VM::VM(std::string file) :
	_parser(file)
{
#ifdef __unix
	_factory.LoadDir("./libs");
#elif _WIN32
	_factory.LoadDir("./libs");
#endif
}

VM::~VM()
{
	// TODO Auto-generated destructor stub
}

void VM::run()
{
	Instruction *ins;
	try
	{
		while ((ins = _parser.getNextInstruction()))
		{
			ins->execute();
		}
	} catch (MyException e)
	{
		std::cout << "The VM ended unexpectidily, exception value: "
				<< e.what() << std::endl;
	}
}

VM *VM::getInstance(std::string file)
{
	if (!_mine)
		_mine = new VM(file);
	return (_mine);
}

void VM::deleteinstance()
{
	delete _mine;
	_mine = NULL;
}

VM *VM::_mine = NULL;

Factory &VM::getFactory()
{
	return _factory;
}

const std::list<IType *> &VM::getStack()
{
	return _stack;
}

void VM::push(IType *obj)
{
	_stack.push_front(obj);
}

IType * VM::pop()
{
	IType *obj2 = _stack.front();
	_stack.pop_front();
	return (obj2);
}
