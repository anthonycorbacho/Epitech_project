/*
 * PrototypeInstruction.h
 *
 *  Created on: Jun 12, 2010
 *      Author: matt
 */

#ifndef PROTOTYPEINSTRUCTION_H_
#define PROTOTYPEINSTRUCTION_H_

#include "Factory.h"
#include "myException.h"
#include "instruction.hpp"

#include <map>
class VM;
class PrototypeInstruction
{
public:
	PrototypeInstruction();
	virtual ~PrototypeInstruction();

	Instruction *cloneInstruction(const std::string &keyword, const std::string &args);
	void LoadInstr();

private:
	std::map<std::string, Instruction *> _mapInstructions;
};

#endif /* PROTOTYPEINSTRUCTION_H_ */
