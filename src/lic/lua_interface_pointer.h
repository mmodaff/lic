//
// lua_interface_pointer.h - pointer version of the templated class LuaInterface
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_LUA_INERFACE_POINTER_H
#define LIC_LUA_INERFACE_POINTER_H

#include "lua_interface_base.h"

namespace lic
{

template <typename T>
class LuaInterface<T*> : public LuaInterfaceBase<T>
{
public:
	typedef LuaInterfaceBase<T> Base;

	static void Push(lua_State* pL, T* pObj, bool owns = false);
	static T* Get(lua_State* pL, int index, bool validate);
};

}

#endif
