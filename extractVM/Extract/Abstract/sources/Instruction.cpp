/*
 * Instruction.cpp
 *
 *  Created on: Jun 12, 2010
 *      Author: matt
 */

#include "instruction.hpp"

Instruction::Instruction()
{

}

Instruction::~Instruction()
{

}

std::string Instruction::extractType(const std::string args)
{
	size_t posFirst = args.find_first_not_of(" \t");
	size_t posLast = args.find_first_of(" \t(", posFirst);
	return args.substr(posFirst, posLast - posFirst);
}

void Instruction::trim(std::string& str)
{
	std::string::size_type pos1 = str.find_first_not_of(" \t\n\r");
	std::string::size_type pos2 = str.find_last_not_of(" \t\n\r");
	str = str.substr(pos1 == std::string::npos ? 0 : pos1, 
		pos2 == std::string::npos ? str.length() - 1 : pos2 - pos1 + 1);
}

void Instruction::cutCommentary(std::string &)
{

}
