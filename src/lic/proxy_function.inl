//
// proxy_function.inl - Templated lua functions that call out to other functions
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_PROXY_FUNCTION_INL
#define LIC_PROXY_FUNCTION_INL

#include "proxy_function.h"
#include "lua_interface.h"
#include "util.h"
extern "C"
{
#include <lua.h>
}

namespace lic
{

template <void (*Fn)()>
int ProxyFunctionVoid(lua_State* pL)
{
	ValidateNumArgs(pL, 0);
	Fn();
	return 0;
}

template <typename A1, void(*Fn)(A1)>
int ProxyFunctionVoid(lua_State* pL)
{
	ValidateNumArgs(pL, 1);
	Fn(lic::LuaInterface<A1>::Get(pL, 1, true));
	return 0;
}

template <typename A1, typename A2, void(*Fn)(A1, A2)>
int ProxyFunctionVoid(lua_State* pL)
{
	ValidateNumArgs(pL, 2);
	Fn(LuaInterface<A1>::Get(pL, 1, true), 
		LuaInterface<A2>::Get(pL, 2, true)
		);
	return 0;
}

template <typename A1, typename A2, typename A3, void(*Fn)(A1, A2, A3)>
int ProxyFunctionVoid(lua_State* pL)
{
	ValidateNumArgs(pL, 3);
	Fn(LuaInterface<A1>::Get(pL, 1, true), 
		LuaInterface<A2>::Get(pL, 2, true),
		LuaInterface<A3>::Get(pL, 3, true)
		);
	return 0;
}

template <typename A1, typename A2, typename A3, typename A4, void(*Fn)(A1, A2, A3, A4)>
int ProxyFunctionVoid(lua_State* pL)
{
	ValidateNumArgs(pL, 4);
	Fn(LuaInterface<A1>::Get(pL, 1, true), 
		LuaInterface<A2>::Get(pL, 2, true),
		LuaInterface<A3>::Get(pL, 3, true),
		LuaInterface<A4>::Get(pL, 4, true)
		);
	return 0;
}

template <typename A1, typename A2, typename A3, typename A4, typename A5, void(*Fn)(A1, A2, A3, A4, A5)>
int ProxyFunctionVoid(lua_State* pL)
{
	ValidateNumArgs(pL, 5);
	Fn(LuaInterface<A1>::Get(pL, 1, true), 
		LuaInterface<A2>::Get(pL, 2, true),
		LuaInterface<A3>::Get(pL, 3, true),
		LuaInterface<A4>::Get(pL, 4, true),
		LuaInterface<A5>::Get(pL, 5, true)
		);
	return 0;
}

template <typename Ret, Ret (*Fn)()>
int ProxyFunctionRet(lua_State* pL)
{
	ValidateNumArgs(pL, 0);
	LuaInterface<Ret>::Push(pL, Fn());
	return 1;
}

template <typename Ret, typename A1, Ret (*Fn)(A1)>
int ProxyFunctionRet(lua_State* pL)
{
	ValidateNumArgs(pL, 1);
	LuaInterface<Ret>::Push(pL, Fn(
		LuaInterface<A1>::Get(pL, 1, true)
		));
	return 1;
}


template <typename Ret, typename A1, typename A2, Ret (*Fn)(A1, A2)>
int ProxyFunctionRet(lua_State* pL)
{
	ValidateNumArgs(pL, 2);
	LuaInterface<Ret>::Push(pL, Fn(
		LuaInterface<A1>::Get(pL, 1, true),
		LuaInterface<A2>::Get(pL, 2, true)
		));
	return 1;
}

template <typename Ret, typename A1, typename A2, typename A3, Ret (*Fn)(A1, A2, A3)>
int ProxyFunctionRet(lua_State* pL)
{
	ValidateNumArgs(pL, 3);
	LuaInterface<Ret>::Push(pL, Fn(
		LuaInterface<A1>::Get(pL, 1, true),
		LuaInterface<A2>::Get(pL, 2, true),
		LuaInterface<A3>::Get(pL, 3, true)
		));
	return 1;
}

template <typename Ret, typename A1, typename A2, typename A3, typename A4, Ret (*Fn)(A1, A2, A3, A4)>
int ProxyFunctionRet(lua_State* pL)
{
	ValidateNumArgs(pL, 4);
	LuaInterface<Ret>::Push(pL, Fn(
		LuaInterface<A1>::Get(pL, 1, true),
		LuaInterface<A2>::Get(pL, 2, true),
		LuaInterface<A3>::Get(pL, 3, true),
		LuaInterface<A4>::Get(pL, 4, true)
		));
	return 1;
}

template <typename Ret, typename A1, typename A2, typename A3, typename A4, typename A5, Ret (*Fn)(A1, A2, A3, A4, A5)>
int ProxyFunctionRet(lua_State* pL)
{
	ValidateNumArgs(pL, 5);
	LuaInterface<Ret>::Push(pL, Fn(
		LuaInterface<A1>::Get(pL, 1, true),
		LuaInterface<A2>::Get(pL, 2, true),
		LuaInterface<A3>::Get(pL, 3, true),
		LuaInterface<A4>::Get(pL, 4, true),
		LuaInterface<A5>::Get(pL, 5, true)
		));
	return 1;
}

}

#endif
