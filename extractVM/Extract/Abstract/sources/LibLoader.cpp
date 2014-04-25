/*
 * LibLoader.cpp
 *
 *  Created on: Jun 6, 2010
 *      Author: matt
 */
#define _POSIX_SOURCE

#include "LibLoader.h"
#include "Factory.h"

#include <iostream>
#include <exception>
#include <sys/types.h>


#ifdef _WIN32
#include <windows.h>
#include "direntWin.h"
#elif __unix
#include <dlfcn.h>
#include <dirent.h>
#endif

LibLoader::LibLoader()
{
#ifndef __unix
#ifndef _WIN32
	throw(MyException("Unsupported system dude.."));
#endif
#endif
}

void LibLoader::unloadFromPath(const std::string & path)
{
}

#ifdef _WIN32
std::wstring s2ws(const std::string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0); 
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}
#endif

void *LibLoader::loadFromPath(const std::string & p)
{
	
	std::cout << "loading lib: " << p << std::endl;
#ifdef __unix
	void *lib;
	lib = dlopen(p.c_str(), RTLD_LAZY);
#elif _WIN32
	#ifdef UNICODE
	std::wstring stemp = s2ws(p);
	HINSTANCE lib = LoadLibrary(stemp.c_str());
	#else
	HINSTANCE lib = LoadLibrary(p.c_str());
	#endif
#endif
	if (!lib)
	{
		char *error;
		#ifdef __unix
		if ((error = dlerror()))
		#else
		if (!lib)
			error = "Cannot open the lib";
		#endif
			throw(MyException(error));
	}
	_libs[lib] = p;
	return lib;
}

void *LibLoader::getFromPath(const std::string & path) const
{
	std::map<void *, std::string>::const_iterator it = _libs.begin();
	std::map<void *, std::string>::const_iterator ite = _libs.end();

	std::cout << "get from path: " << path << "$" << std::endl;
	while (it != ite)
	{
		if (it->second == path)
			return (it->first);
		else
			std::cout << "val: " << it->second << std::endl;
		++it;
	}
	throw(MyException("No such lib loaded dude.."));
}

void LibLoader::unloadFromInputPoint(void *inputPoint)
{
	std::map<void *, std::string>::iterator it;
	if ((it = _libs.find(inputPoint)) != _libs.end())
	{
#ifdef __unix
		if (dlclose(inputPoint))
#elif _WIN32
			if (FreeLibrary((HMODULE)inputPoint))
#endif
			throw(MyException("Cannot close the lib.."));
		_libs.erase(it);
	}
	else
		throw(MyException("No such lib opened dude.."));
}

LibLoader::~LibLoader()
{
	std::map<void *, std::string>::const_iterator it = _libs.begin();
	std::map<void *, std::string>::const_iterator ite = _libs.end();

	while (it != ite)
	{
		unloadFromInputPoint(it->first);
		++it;
	}
}

void LibLoader::addSuffix(std::string &path) const
{
#ifdef __unix
	path += ".so";
#elif _win32
	path += ".dll";
#endif
}

void *LibLoader::getSym(void *inputPoint, const std::string &symName)
{
	void *symbol;

	if (_libs.find(inputPoint) == _libs.end())
		throw(MyException("No such lib loaded dude.."));
#ifdef __unix
	symbol = dlsym(inputPoint, symName.c_str());
#elif _WIN32
	symbol = GetProcAddress((HMODULE)inputPoint, symName.c_str());
#endif
	return symbol;
}
void LibLoader::loadDirectory(const std::string &path)
{
	struct dirent *file;
	DIR *rep;

	rep = opendir(path.c_str());
	if (rep)
	{
		while ((file = readdir(rep)))
		{
			std::string filename = file->d_name;
			if (suffixMatch(filename))
			{
				std::string toLoad;
#ifdef __unix
				toLoad = path + "/" + filename;
#elif _WIN32
				toLoad = path + "\\" + filename;
#endif
				loadFromPath(toLoad);
			}
		}
		closedir(rep);
	}
}

bool LibLoader::suffixMatch(const std::string &filename) const
{
	std::string suffix;
#ifdef __unix
	suffix = "so";
#elif _WIN32
	suffix= "dll";
#endif
	size_t pos = filename.rfind(suffix);
	return ( pos != std::string::npos && pos == filename.size() - suffix.size());
}
