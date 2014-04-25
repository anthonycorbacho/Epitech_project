/*
 * VM.h
 *
 *  Created on: Jun 12, 2010
 *      Author: matt
 */

#ifndef VM_H_
#define VM_H_

#include "Factory.h"
#include "parsing.hpp"
#include <string>
#include <list>
#include <IObject.hpp>
#include "IType.hpp"

class VM
{
public:
	virtual ~VM();

	static VM *getInstance(std::string file = "");
	static void deleteinstance();

	void run();
	Factory &getFactory();

	const std::list<IType *> &getStack();
		void push(IType *);
		IType * pop();

private:
	VM(std::string file);
	Parsing _parser;
	Factory _factory;
	static VM *_mine;
	std::list<IType *> _stack;
};

#endif /* VM_H_ */
