//
// proxy_singleton.h - Templated lua functions that call out to functions that are part of singletons
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_PROXY_SINGLETON_H
#define LIC_PROXY_SINGLETON_H

#include "proxy_function.h"

struct lua_State;

namespace lic
{

template <typename T, T& (*GetFn)()>
void RegisterSingletonGlobal(lua_State* pL, const char* pName);

template <typename T, T& (*GetFn)(), void (T::*Fn)()>
class ProxySingletonFunctionVoid0 : public ProxyFunctionBase<ProxySingletonFunctionVoid0<T, GetFn, Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <typename T, T& (*GetFn)(), typename A1, void (T::*Fn)(A1)>
class ProxySingletonFunctionVoid1 : public ProxyFunctionBase<ProxySingletonFunctionVoid1<T, GetFn, A1, Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <typename T, T& (*GetFn)(), typename Ret, Ret (T::*Fn)()>
class ProxySingletonFunctionRet0 : public ProxyFunctionBase<ProxySingletonFunctionRet0<T, GetFn, Ret, Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <typename T, T& (*GetFn)(), typename Ret, typename A1, Ret (T::*Fn)(A1)>
class ProxySingletonFunctionRet1 : public ProxyFunctionBase<ProxySingletonFunctionRet1<T, GetFn, Ret, A1, Fn> >
{
public:
	static int Call(lua_State* pL);
};

}

#endif
