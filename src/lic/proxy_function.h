//
// proxy_function.h - Templated lua functions that call out to other functions
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_PROXY_FUNCTION_H
#define LIC_PROXY_FUNCTION_H


struct lua_State;

namespace lic
{

template <typename DerivedClass>
class ProxyFunctionBase
{
public:
	static void Register(lua_State* pL, const char* pName);
};

template <void (*Fn)()>
class ProxyFunctionVoid0 : public ProxyFunctionBase<ProxyFunctionVoid0<Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <typename A1, void (*Fn)(A1)>
class ProxyFunctionVoid1 : public ProxyFunctionBase<ProxyFunctionVoid1<A1, Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <typename A1, typename A2, void(*Fn)(A1, A2)>
class ProxyFunctionVoid2 : public ProxyFunctionBase<ProxyFunctionVoid2<A1, A2, Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <typename A1, typename A2, typename A3, void(*Fn)(A1, A2, A3)>
class ProxyFunctionVoid3 : public ProxyFunctionBase<ProxyFunctionVoid3<A1, A2, A3, Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <typename A1, typename A2, typename A3, typename A4, void(*Fn)(A1, A2, A3, A4)>
class ProxyFunctionVoid4 : public ProxyFunctionBase<ProxyFunctionVoid4<A1, A2, A3, A4, Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <typename A1, typename A2, typename A3, typename A4, typename A5, void(*Fn)(A1, A2, A3, A4, A5)>
class ProxyFunctionVoid5 : public ProxyFunctionBase<ProxyFunctionVoid5<A1, A2, A3, A4, A5, Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <typename Ret, Ret (*Fn)()>
class ProxyFunctionRet0 : public ProxyFunctionBase<ProxyFunctionRet0<Ret, Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <typename Ret, typename A1, Ret (*Fn)(A1)>
class ProxyFunctionRet1 : public ProxyFunctionBase<ProxyFunctionRet1<Ret, A1, Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <typename Ret, typename A1, typename A2, Ret (*Fn)(A1, A2)>
class ProxyFunctionRet2 : public ProxyFunctionBase<ProxyFunctionRet2<Ret, A1, A2, Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <typename Ret, typename A1, typename A2, typename A3, Ret (*Fn)(A1, A2, A3)>
class ProxyFunctionRet3 : public ProxyFunctionBase<ProxyFunctionRet3<Ret, A1, A2, A3, Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <typename Ret, typename A1, typename A2, typename A3, typename A4, Ret (*Fn)(A1, A2, A3, A4)>
class ProxyFunctionRet4 : public ProxyFunctionBase<ProxyFunctionRet4<Ret, A1, A2, A3, A4, Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <typename Ret, typename A1, typename A2, typename A3, typename A4, typename A5, Ret (*Fn)(A1, A2, A3, A4, A5)>
class ProxyFunctionRet5 : public ProxyFunctionBase<ProxyFunctionRet5<Ret, A1, A2, A3, A4, A5, Fn> >
{
public:
	static int Call(lua_State* pL);
};

template <int (*Fn)(lua_State*)>
class ProxyFunctionLua : public ProxyFunctionBase<ProxyFunctionLua<Fn> >
{
public:
	static int Call(lua_State* pL);
};

}

#endif
