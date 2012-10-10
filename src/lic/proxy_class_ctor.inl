//
// proxy_class_ctor.inl - Templated lua functions that create objects
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_PROXY_CLASS_CTOR_INL
#define LIC_PROXY_CLASS_CTOR_INL

#include "proxy_class_ctor.h"
#include "proxy_function.inl"
#include "lua_interface.h"
#include "util.h"

struct lua_State;

namespace lic
{

template <typename T>
int ProxyClassCtor0<T>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 0);
	LuaInterface<T*>::Push(pL, new T, true);
	return 1;
}

template <typename T, typename A1>
int ProxyClassCtor1<T, A1>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 1);
	LuaInterface<T*>::Push(pL, new T(
		LuaInterface<A1>::Get(pL, 1, true)
		), true);
	return 1;
}

template <typename T, typename A1, typename A2>
int ProxyClassCtor2<T, A1, A2>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 2);
	LuaInterface<T*>::Push(pL, new T(
		LuaInterface<A1>::Get(pL, 1, true),
		LuaInterface<A2>::Get(pL, 2, true)
		), true);
	return 1;
}

template <typename T, typename A1, typename A2, typename A3>
int ProxyClassCtor3<T, A1, A2, A3>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 3);
	LuaInterface<T*>::Push(pL, new T(
		LuaInterface<A1>::Get(pL, 1, true),
		LuaInterface<A2>::Get(pL, 2, true),
		LuaInterface<A3>::Get(pL, 3, true)
		), true);
	return 1;
}

template <typename T, typename A1, typename A2, typename A3, typename A4>
int ProxyClassCtor4<T, A1, A2, A3, A4>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 4);
	LuaInterface<T*>::Push(pL, new T(
		LuaInterface<A1>::Get(pL, 1, true),
		LuaInterface<A2>::Get(pL, 2, true),
		LuaInterface<A3>::Get(pL, 3, true),
		LuaInterface<A4>::Get(pL, 4, true)
		), true);
	return 1;
}

}

#endif
