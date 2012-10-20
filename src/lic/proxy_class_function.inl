 //
// proxy_singleton_function.inl - Implementation of templated lua functions that call out to functions that are part of singletons
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_PROXY_CLASS_FUNCTION_INL
#define LIC_PROXY_CLASS_FUNCTION_INL

#include "proxy_class_function.h"
#include "lua_interface.h"
#include "util.h"

struct lua_State;

namespace lic
{

template <typename DerivedClass>
void ProxyClassFunctionBase<DerivedClass>::Register(lua_State* pL, const char* pName)
{
	LuaInterface<typename DerivedClass::ClassType*>::RegisterMemberFunc(pL, pName, DerivedClass::Call);
}

template <typename T, int (T::*Fn)(lua_State* pL)>
int ProxyClassFunctionLua<T, Fn>::Call(lua_State* pL)
{
	ValidateMinArgs(pL, 1);
	T* pObj = LuaInterface<T*>::GetPtr(pL, 1, true);
	lua_remove(pL, 1);
	return (pObj->*Fn)(pL);
};

template <typename T, void (T::*Fn)()>
int ProxyClassFunctionVoid0<T, Fn>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 1);
	(LuaInterface<T*>::GetPtr(pL, 1, true)->*Fn)();
	return 0;
};

template <typename T, typename A1, void (T::*Fn)(A1)>
int ProxyClassFunctionVoid1<T, A1, Fn>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 2);
	(LuaInterface<T*>::GetPtr(pL, 1, true)->*Fn)(
		LuaInterface<A1>::Get(pL, 2, true)
		);
	return 0;
};

template <typename T, typename A1, typename A2, void (T::*Fn)(A1, A2)>
int ProxyClassFunctionVoid2<T, A1, A2, Fn>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 3);
	(LuaInterface<T*>::GetPtr(pL, 1, true)->*Fn)(
		LuaInterface<A1>::Get(pL, 2, true),
		LuaInterface<A2>::Get(pL, 3, true)
		);
	return 0;
};

template <typename T, typename Ret, Ret (T::*Fn)()>
int ProxyClassFunctionRet0<T, Ret, Fn>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 1);
	LuaInterface<Ret>::Push(pL, (LuaInterface<T*>::GetPtr(pL, 1, true)->*Fn)());
	return 1;
};

template <typename T, typename Ret, Ret (T::*Fn)() const>
int ProxyClassConstFunctionRet0<T, Ret, Fn>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 1);
	LuaInterface<Ret>::Push(pL, (LuaInterface<T*>::GetPtr(pL, 1, true)->*Fn)());
	return 1;
};

template <typename T>
int ProxyClassDelete<T>::Call(lua_State* pL)
{
	ValidateNumArgs(pL, 1);
	LuaWrapper<T>* pWrapper = LuaInterface<T>::GetWrapper(pL, 1, true);
	delete pWrapper->pObj;
	pWrapper->pObj = NULL;
	return 0;
}

}

#endif
