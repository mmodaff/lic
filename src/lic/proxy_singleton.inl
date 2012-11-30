//
// proxy_singleton.inl - Implementation of templated lua functions that call out to functions that are part of singletons
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_PROXY_SINGLETON_INL
#define LIC_PROXY_SINGLETON_INL

#include "proxy_singleton.h"
#include "lua_interface.h"
#include "util.h"

struct lua_State;

namespace lic
{

template <typename T, T& (*GetFn)()>
void RegisterSingletonGlobal(lua_State* pL, const char* pName)
{
	LuaInterface<T>::Register(pL);
	LuaInterface<T*>::Push(pL, &GetFn());
	lua_setglobal(pL, pName);
}

template <typename T, T& (*GetFn)(), void (T::*Fn)()>
int ProxySingletonFunctionVoid0<T, GetFn, Fn>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 0);
	(GetFn().*Fn)();
	return 0;
}

template <typename T, T& (*GetFn)(), typename A1, void (T::*Fn)(A1)>
int ProxySingletonFunctionVoid1<T, GetFn, A1, Fn>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 1);
	(GetFn().*Fn)(
		LuaInterface<A1>::Get(pL, 1, true)
		);
	return 0;
}

template <typename T, T& (*GetFn)(), typename Ret, Ret (T::*Fn)()>
int ProxySingletonFunctionRet0<T, GetFn, Ret, Fn>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 0);
	LuaInterface<Ret>::Push(pL, (GetFn().*Fn)());
	return 1;
}

template <typename T, T& (*GetFn)(), typename Ret, typename A1, Ret (T::*Fn)(A1)>
int ProxySingletonFunctionRet1<T, GetFn, Ret, A1, Fn>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 1);
	LuaInterface<Ret>::Push(pL, (GetFn().*Fn)(
		LuaInterface<A1>::Get(pL, 1, true)
		));
	return 1;
}


}

#endif
