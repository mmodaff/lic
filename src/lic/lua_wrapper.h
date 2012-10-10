//
// lua_wrapper.h - Templated class that is created by lua and wraps an object
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_LUA_WRAPPER_H
#define LIC_LUA_WRAPPER_H

namespace lic
{

template <typename T>
struct LuaWrapper
{
	LuaWrapper() : owns(false) {}
	~LuaWrapper()
	{
		if (owns)
			delete pObj;
	}

	T* pObj;
	bool owns;
};

}

#endif
