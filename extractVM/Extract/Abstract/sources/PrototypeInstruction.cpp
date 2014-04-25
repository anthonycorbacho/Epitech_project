/*
 * PrototypeInstruction.cpp
 *
 *  Created on: Jun 12, 2010
 *      Author: matt
 */

#include "../includes/PrototypeInstruction.h"
#include <iostream>
#include "VM.h"
#include "push.hpp"
#include "dump.hpp"
#include "pop.hpp"
#include "operator.hpp"
#include "pop.hpp"
#include "MyAssert.h"

PrototypeInstruction::PrototypeInstruction()
{
	LoadInstr();
}

PrototypeInstruction::~PrototypeInstruction()
{

}

Instruction *PrototypeInstruction::cloneInstruction(const std::string &keyword,
		const std::string &args)
{
	if (_mapInstructions.find(keyword) != _mapInstructions.end())
	{
		Instruction *ins = _mapInstructions[keyword];
		if (ins->analyse(keyword, args))
			return (ins->clone());
		else
			throw(MyException("Invalid args for keyword: " + keyword
					+ ", args: " + args));
	}
	else
		throw(MyException("Keyword: " + keyword + " not supported"));
}

void PrototypeInstruction::LoadInstr()
{
	_mapInstructions["push"] = new Push();
	_mapInstructions["add"] = new Operator();
	_mapInstructions["dump"] = new Dump();
	_mapInstructions["pop"] = new Pop();
	_mapInstructions["assert"] = new MyAssert();
	_mapInstructions["divide"] = _mapInstructions["add"];
	_mapInstructions["multiply"] = _mapInstructions["add"];
	_mapInstructions["substract"] = _mapInstructions["add"];
}
