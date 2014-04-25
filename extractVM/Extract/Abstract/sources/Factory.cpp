/*
 * Factory.cpp
 *
 *  Created on: Jun 11, 2010
 *      Author: matt
 */

#include "../includes/Factory.h"
#include <iostream>
#include <sstream>
#include <string>
#include "IType.hpp"

void Factory::LoadDir(const std::string &path)
{
	_libLoad.loadDirectory(path);
	std::map<void *, std::string>::const_iterator it = _libLoad._libs.begin();
	std::map<void *, std::string>::const_iterator ite = _libLoad._libs.end();

	while (it != ite)
	{
		std::string name = it->second;
#ifdef __unix
		size_t pos = name.find_last_of("/");
#elif _WIN32
		size_t pos = name.find_last_of("\\");
#endif
		if (pos != std::string::npos)
			name = name.substr(pos + 1);
		void *handle = _libLoad.getSym(it->first, "maker");
		typedef IObject *(*typetmp)();
		union { typetmp func; void * obj; } alias;
		alias.obj = handle;
		typetmp m = alias.func;
		std::string ind;
		if ((pos = name.find_first_of(".")) != std::string::npos)
			ind = name.substr(3, pos - 3);
		_mapObject[ind] = m();
		name = name.substr(4 + ind.size());
		std::stringstream stream(name);
		IType *obj = dynamic_cast<IType *>(_mapObject[ind]);
		int p;
		stream >> p;
		obj->setPrecision(p);
		std::cout << "Adding in Type factory: Typename: " << ind << " Precision: " <<  p << std::endl;
		++it;
	}
}

IObject *Factory::clone(const std::string &type)
{

	std::cout << "Factory: cloning " << type << std::endl;
	if (_mapObject.find(type) != _mapObject.end())
		return _mapObject[type]->Clone();
	else
		throw(MyException("Factory: unknown type"));
}
