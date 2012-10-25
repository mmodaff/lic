//
// proxy_class_function.h - Templated lua functions that call out to class methods
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_PROXY_CLASS_FUNCTION_H
#define LIC_PROXY_CLASS_FUNCTION_H

struct lua_State;

namespace lic
{

template <typename DerivedClass>
class ProxyClassFunctionBase
{
public:
	static void Register(lua_State* pL, const char* pName);
};

template <typename T, int (T::*Fn)(lua_State* pL)>
class ProxyClassFunctionLua : public ProxyClassFunctionBase<ProxyClassFunctionLua<T, Fn> >
{
public:
	typedef T ClassType;
	static int Call(lua_State* pL);
};

template <typename T, void (T::*Fn)()>
class ProxyClassFunctionVoid0 : public ProxyClassFunctionBase<ProxyClassFunctionVoid0<T, Fn> >
{
public:
	typedef T ClassType;
	static int Call(lua_State* pL);
};

template <typename T, typename A1, void (T::*Fn)(A1)>
class ProxyClassFunctionVoid1 : public ProxyClassFunctionBase<ProxyClassFunctionVoid1<T, A1, Fn> >
{
public:
	typedef T ClassType;
	static int Call(lua_State* pL);
};

template <typename T, typename A1, typename A2, void (T::*Fn)(A1, A2)>
class ProxyClassFunctionVoid2 : public ProxyClassFunctionBase<ProxyClassFunctionVoid2<T, A1, A2, Fn> >
{
public:
	typedef T ClassType;
	static int Call(lua_State* pL);
};

template <typename T, typename Ret, Ret (T::*Fn)()>
class ProxyClassFunctionRet0 : public ProxyClassFunctionBase<ProxyClassFunctionRet0<T, Ret, Fn> >
{
public:
	typedef T ClassType;
	static int Call(lua_State* pL);
};

template <typename T, typename Ret, typename A1, Ret (T::*Fn)(A1)>
class ProxyClassFunctionRet1 : public ProxyClassFunctionBase<ProxyClassFunctionRet1<T, Ret, A1, Fn> >
{
public:
	typedef T ClassType;
	static int Call(lua_State* pL);
};

template <typename T, typename Ret, typename A1, typename A2, Ret (T::*Fn)(A1, A2)>
class ProxyClassFunctionRet2 : public ProxyClassFunctionBase<ProxyClassFunctionRet2<T, Ret, A1, A2, Fn> >
{
public:
	typedef T ClassType;
	static int Call(lua_State* pL);
};

template <typename T, typename Ret, Ret (T::*Fn)() const>
class ProxyClassConstFunctionRet0 : public ProxyClassFunctionBase<ProxyClassConstFunctionRet0 <T, Ret, Fn> >
{
public:
	typedef T ClassType;
	static int Call(lua_State* pL);
};

template <typename T>
class ProxyClassDelete : public ProxyClassFunctionBase<ProxyClassDelete<T> >
{
public:
	typedef T ClassType;
	static int Call(lua_State* pL);
};

}

#endif
