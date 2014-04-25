/*
 * Int32.h
 *
 *  Created on: Jun 11, 2010
 *      Author: matt
 */

#ifndef TempType_H_
#define TempType_H_

#define TYPESTRING "double"
#define TYPEWANTED double

#include "IType.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include "myException.h"

template<typename T>
class TempType: public IType
{
public:
	TempType();
	~TempType();

	std::string get() const;
	void set(const std::string &);

	const std::string& ToString() const;
	const std::string& GetType() const;
	bool Equals(const IObject &value) const;
	IObject* Clone() const;

	IObject* Add(const IOperand &object);
	IObject* Subtract(const IOperand &object);
	IObject* Multiply(const IOperand &object);
	IObject* Divide(const IOperand &object);

private:
	std::string _type;
	T _value;
};

template<typename t>
TempType<t>::TempType()
{
	_type = TYPESTRING;
	_value = 0;
}

template<typename t>
TempType<t>::~TempType()
{
}

template<typename t>
const std::string & TempType<t>::GetType() const
{
	return _type;
}

template<typename t>
std::string TempType<t>::get() const
{
	std::string str;
	std::ostringstream stream(str);
	stream << _value;
	return stream.str();
}

template<typename t>
void TempType<t>::set(const std::string & string)
{
	std::istringstream stream(string);
	stream >> _value;
}

template<typename t>
const std::string & TempType<t>::ToString() const
{
	std::string toString;
	std::stringstream stream(toString);
	stream << "Type: " << _type << ", value: " << _value << std::endl;
	return *(new std::string(stream.str()));
}

template<typename t>
IObject *TempType<t>::Add(const IOperand & object)
{
	const IType * obj2 = dynamic_cast<const IType *> (&object);
	if (this->getPrecision() >= obj2->getPrecision())
	{
		TempType *res = new TempType();
		std::string v = obj2->get();
		std::stringstream stream(v);
		t i;
		stream >> i;
		res->_value = this->_value + i;
		return (res);
	}
	{
		IType *clone = dynamic_cast<IType *> (object.Clone());
		clone->Add(*this);
		return clone;
	}
}

template<typename t>
IObject *TempType<t>::Subtract(const IOperand & object)
{
	const IType * obj2 = dynamic_cast<const IType *> (&object);
	if (this->getPrecision() >= obj2->getPrecision())
	{
		TempType *res = new TempType();
		std::string v = obj2->get();
		std::stringstream stream(v);
		t i;
		stream >> i;
		res->_value = this->_value - i;
		return (res);
	}
	{
		IType *clone = dynamic_cast<IType *> (object.Clone());
		clone->Subtract(*this);
		return clone;
	}
}

template<typename t>
IObject *TempType<t>::Multiply(const IOperand & object)
{
	const IType * obj2 = dynamic_cast<const IType *> (&object);
	if (this->getPrecision() >= obj2->getPrecision())
	{
		TempType<t> *res = new TempType<t> ();
		std::string v = obj2->get();
		std::stringstream stream(v);
		t i;
		stream >> i;
		res->_value = this->_value * i;
		return (res);
	}
	{
		IType *clone = dynamic_cast<IType *> (object.Clone());
		clone->Multiply(*this);
		return clone;
	}
}

template<typename t>
IObject *TempType<t>::Divide(const IOperand & object)
{
	const IType * obj2 = dynamic_cast<const IType *> (&object);
	if (this->getPrecision() >= obj2->getPrecision())
	{
		TempType<t>*res = new TempType<t> ();
		std::string v = obj2->get();
		std::stringstream stream(v);
		t i;
		stream >> i;
		if (!i)
			throw(MyException("Cannot divide by zero"));
		res->_value = this->_value / i;
		return (res);
	}
	{
		IType *clone = dynamic_cast<IType *> (object.Clone());
		clone->Divide(*this);
		return clone;
	}
}

template<typename t>
bool TempType<t>::Equals(const IObject & object) const
{
	const IType * obj2 = dynamic_cast<const IType *> (&object);
	if (this->getPrecision() != obj2->getPrecision() || obj2->GetType()
			!= this->GetType())
		return false;
	const TempType<t> * obj3 = dynamic_cast<const TempType<t> *> (&object);
	return (obj3->_value == this->_value);
}

template<typename t>
IObject *TempType<t>::Clone() const
{
	return (new TempType<t> (*this));
}

extern "C"
{
#ifdef __unix
IObject *maker();
void deleter(IObject *);
#elif _WIN32
__declspec(dllexport) IObject *maker();
__declspec(dllexport) void deleter(IObject *);
#endif
}

IObject *maker()
{
	return new TempType<TYPEWANTED> ();
}

void deleter(IObject *o)
{
	delete o;
}

#endif /* TempType_H_ */
