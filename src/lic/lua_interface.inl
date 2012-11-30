//
// lua_interface.inl - Templated class that handles most of the interface responsibilities
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_LUA_INTERFACE_INL
#define LIC_LUA_INTERFACE_INL

#include "lua_interface.h"
#include "lua_wrapper.h"

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
		LuaWrapper<T>* pData = LuaInterface<T>::CreateWrapperOnTop(pL);
		pData->pObj = pObj;
		pData->owns = owns;
	}
	else
		lua_pushnil(pL);
}

template<typename T>
T* LuaInterface<T*>::Get(lua_State* pL, int index, bool validate)
{
	return Base::GetPtr(pL, index, validate);
}

template<typename T>
T* LuaInterface<T*>::GetPtr(lua_State* pL, int index, bool validate)
{
	return Base::GetPtr(pL, index, validate);
}

template<typename T>
void LuaInterface<T&>::Push(lua_State* pL, T& obj)
{
		LuaWrapper<T>* pData = LuaInterface<T>::CreateWrapperOnTop(pL);
		pData->pObj = &obj;
		pData->owns = false;
}

template <typename T>
T& LuaInterface<T&>::Get(lua_State* pL, int index, bool validate)
{
	return *(Base::GetPtr(pL, index, validate));
}

template <typename T>
T* LuaInterface<T&>::GetPtr(lua_State* pL, int index, bool validate)
{
	return Base::GetPtr(pL, index, validate);
}

template<typename T>
void LuaInterface<const T&>::Push(lua_State* pL, const T& obj)
{
		LuaWrapper<T>* pData = LuaInterface<T>::CreateWrapperOnTop(pL);
		pData->pObj = (T*)&obj;
		pData->owns = false;
}

template <typename T>
const T& LuaInterface<const T&>::Get(lua_State* pL, int index, bool validate)
{
	return *(Base::GetPtr(pL, index, validate));
}

template <typename T>
const T* LuaInterface<const T&>::GetPtr(lua_State* pL, int index, bool validate)
{
	return Base::GetPtr(pL, index, validate);
}


}

#endif
