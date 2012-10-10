//
// proxy_class_ctor.h - Templated lua functions that create objects
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_PROXY_CLASS_CTOR_H
#define LIC_PROXY_CLASS_CTOR_H

#include "proxy_function.h"

struct lua_State;

namespace lic
{

template <typename T>
class ProxyClassCtor0 : public ProxyFunctionBase<ProxyClassCtor0<T> >
{
public:
	static int Call(lua_State* pL);
};

template <typename T, typename A1>
class ProxyClassCtor1 : public ProxyFunctionBase<ProxyClassCtor1<T, A1> >
{
public:
	static int Call(lua_State* pL);
};

template <typename T, typename A1, typename A2>
class ProxyClassCtor2 : public ProxyFunctionBase<ProxyClassCtor2<T, A1, A2> >
{
public:
	static int Call(lua_State* pL);
};

template <typename T, typename A1, typename A2, typename A3>
class ProxyClassCtor3 : public ProxyFunctionBase<ProxyClassCtor3<T, A1, A2, A3> >
{
public:
	static int Call(lua_State* pL);
};

template <typename T, typename A1, typename A2, typename A3, typename A4>
class ProxyClassCtor4 : public ProxyFunctionBase<ProxyClassCtor4<T, A1, A2, A3, A4> >
{
public:
	static int Call(lua_State* pL);
};

}

#endif
