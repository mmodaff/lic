//
// lua_interface_default.h - Implementation for the default version of the templated class LuaInterface, which is the
// workhorse class of lic.
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "lua_interface_default.h"
#include "lua_wrapper.h"

extern "C"
{
#include <lua.h>
}

namespace lic
{

template<typename T>
void LuaInterface<T>::Push(lua_State* pL, T obj)
{
	LuaWrapper<T>* pData;
	pData = new (lua_newuserdata(pL, sizeof(LuaWrapper<T>))) LuaWrapper<T>();
	pData->pObj = new T(obj);
	pData->owns = true;
	Base::PushMetatable(pL);
	lua_setmetatable(pL, -2);
}

template<typename T>
T LuaInterface<T>::Get(lua_State* pL, int index, bool validate)
{
	return *(Base::GetPtr(pL, index, validate));
}

}
