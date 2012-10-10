//
// lua_interface_reference.h - reference version of the templated class LuaInterface
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_LUA_INTERFACE_REFERENCE_H
#define LIC_LUA_INTERFACE_REFERENCE_H

#include "lua_interface_base.h"

namespace lic
{

template <typename T>
class LuaInterface<T&> : public LuaInterfaceBase<T>
{
public:
	typedef LuaInterfaceBase<T> Base;

	static void Push(lua_State* pL, T& pObj);
	static T& Get(lua_State* pL, int index, bool validate);
};

template <typename T>
class LuaInterface<const T&> : public LuaInterfaceBase<T>
{
public:
	typedef lic::LuaInterfaceBase<T> Base;

	static void Push(lua_State* pL, const T& pObj);
	static const T& Get(lua_State* pL, int index, bool validate);
};

}

#endif
