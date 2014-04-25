/*
 * IType.hpp
 *
 *  Created on: Jun 11, 2010
 *      Author: matt
 */

#ifndef ITYPE_HPP_
#define ITYPE_HPP_

#include "IOperand.hpp"
#include <string>

class IType: public IOperand
{
public:
	virtual std::string get() const = 0;
	virtual void set(const std::string &) = 0;

	int getPrecision() const;
	void setPrecision(int precision);

protected:
	int _precision;
};

#endif /* ITYPE_HPP_ */
