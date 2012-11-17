//
// lua_interface_reference.h - Implementation of the reference version of the templated class LuaInterface
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "lua_interface_reference.h"

extern "C"
{
#include <lua.h>
}

namespace lic
{

template<typename T>
void LuaInterface<T&>::Push(lua_State* pL, T& obj)
{
	LuaWrapper<T>* pData = new (lua_newuserdata(pL, sizeof(LuaWrapper<T>))) LuaWrapper<T>();

	pData->pObj = &obj;
	Base::PushMetatable(pL);
	lua_setmetatable(pL, -2);
}

template<typename T>
T& LuaInterface<T&>::Get(lua_State* pL, int index, bool validate)
{
	return *Base::GetPtr(pL, index, validate);
}

/////////////////////////////////////////

template<typename T>
void LuaInterface<const T&>::Push(lua_State* pL, const T& obj)
{
	LuaWrapper<T>* pData = new (lua_newuserdata(pL, sizeof(LuaWrapper<T>))) LuaWrapper<T>();

	pData->pObj = (T*)&obj;
	Base::PushMetatable(pL);
	lua_setmetatable(pL, -2);
}

template<typename T>
const T& LuaInterface<const T&>::Get(lua_State* pL, int index, bool validate)
{
	return *Base::GetPtr(pL, index, validate);
}


}
