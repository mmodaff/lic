//
// register_global_macros.h - Macros to make registering global functions easier
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_REGISTER_GLOBAL_MACROS_H
#define LIC_REGISTER_GLOBAL_MACROS_H

#include "string_registrant.h"
#include "proxy_function.inl"
#include "proxy_singleton.inl"

#define LIC_REG_GLOBAL_FUNC_VOID_0(name)																	\
	static lic::StringRegistrant s_ ## name ## Register(lic::ProxyFunctionVoid0<name>::Register, #name)

#define LIC_REG_GLOBAL_FUNC_VOID_1(name, a1)																\
	static lic::StringRegistrant s_ ## name ## Register(lic::ProxyFunctionVoid1<a1, name>::Register, #name)

#define LIC_REG_GLOBAL_FUNC_RET_0(name, ret)																\
	static lic::StringRegistrant s_ ## name ## Register(lic::ProxyFunctionRet0<ret, name>::Register, #name)
	
#define LIC_REG_GLOBAL_FUNC_RET_1(name, ret, a1)															\
	static lic::StringRegistrant s_ ## name ## Register(lic::ProxyFunctionRet1<								\
		ret, a1, name>::Register, #name)

#define LIC_REG_GLOBAL_FUNC_LUA(name)																		\
	static lic::StringRegistrant s_ ## name ## Register(lic::ProxyFunctionLua<name>::Register, #name)


#define LIC_REG_GLOBAL_SINGLETON(singleton, get)																	\
	namespace lic {																									\
	template<> int LuaInterfaceBase<singleton>::GC(lua_State* pL)													\
	{																												\
		LuaWrapper<singleton>* pWrap = (LuaWrapper<singleton>*)lua_touserdata(pL, 1);								\
		pWrap->~LuaWrapper<singleton>();																			\
		return 0;																									\
	}																												\
	}																												\
	template class lic::LuaInterface<singleton*>;																	\
	template<> int lic::LuaInterfaceBase<singleton>::sm_regIndex = -1;												\
	template<> lic::LuaInterfaceBase<singleton>::DispatchMap lic::LuaInterfaceBase<singleton>::sm_dispatchMap =		\
		lic::LuaInterfaceBase<singleton>::DispatchMap();															\
	template<> lic::LuaInterfaceBase<singleton>::SetterMap lic::LuaInterfaceBase<singleton>::sm_setterMap =			\
		lic::LuaInterfaceBase<singleton>::SetterMap();																\
	static lic::StringRegistrant s_ ## singleton ## Register(lic::RegisterSingletonGlobal<singleton,				\
		get>, #singleton)

#define LIC_REG_GLOBAL_SINGLETON_FUNC_VOID_0(singleton, name)												\
	static lic::StringRegistrant s_ ## name ## Register(lic::ProxySingletonFunctionVoid0<					\
		singleton, singleton::Get, &singleton::name>::Register, #name)

#define LIC_REG_GLOBAL_SINGLETON_FUNC_VOID_1(singleton, name, a1)											\
	static lic::StringRegistrant s_ ## name ## Register(lic::ProxySingletonFunctionVoid1<					\
		singleton, singleton::Get, a1, &singleton::name>::Register, #name)

#define LIC_REG_GLOBAL_SINGLETON_FUNC_RET_0(singleton, name, ret)											\
	static lic::StringRegistrant s_ ## name ## Register(lic::ProxySingletonFunctionRet0<					\
		singleton, singleton::Get, ret, &singleton::name>::Register, #name)

#define LIC_REG_GLOBAL_SINGLETON_FUNC_RET_1(singleton, name, ret, a1)										\
	static lic::StringRegistrant s_ ## name ## Register(lic::ProxySingletonFunctionRet1<					\
		singleton, singleton::Get, ret, a1, &singleton::name>::Register, #name)


#endif
