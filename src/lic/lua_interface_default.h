//
// lua_interface_default.h - Default version of the templated class LuaInterface, which is the
// workhorse class of lic.
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_LUA_INTERFACE_DEFAULT_H
#define LIC_LUA_INTERFACE_DEFAULT_H

#include "lua_interface_base.h"

namespace lic
{

template <typename T>
class LuaInterface : public LuaInterfaceBase<T>
{
public:
	typedef LuaInterfaceBase<T> Base;

	static void Push(lua_State* pL, T obj);
	static void PushRefIfObj(lua_State* pL, T& obj);
	static T Get(lua_State* pL, int index, bool validate);
};

}

#endif
