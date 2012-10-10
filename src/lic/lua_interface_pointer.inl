//
// lua_interface_pointer.inl - Implementation of the pointer version of the templated class LuaInterface
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "lua_interface_pointer.h"

extern "C"
{
#include <lua.h>
}

namespace lic
{

template<typename T>
void LuaInterface<T*>::Push(lua_State* pL, T* pObj, bool owns)
{
	if (pObj)
	{
		LuaWrapper<T>* pData = new (lua_newuserdata(pL, sizeof(LuaWrapper<T>))) LuaWrapper<T>();

		pData->pObj = pObj;
		pData->owns = owns;
		Base::PushMetatable(pL);
		lua_setmetatable(pL, -2);
	}
	else
		lua_pushnil(pL);
}

template<typename T>
T* LuaInterface<T*>::Get(lua_State* pL, int index, bool validate)
{
	return Base::GetPtr(pL, index, validate);
}


}
