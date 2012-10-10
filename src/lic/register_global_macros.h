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
#include "proxy_singleton_function.inl"

#define LIC_REG_GLOBAL_FUNC_VOID_0(name)																	\
	static lic::StringRegistrant s_ ## name ## Register(lic::ProxyFunctionVoid0<name>::Register, #name)

#define LIC_REG_GLOBAL_FUNC_VOID_1(name, a1)																\
	static lic::StringRegistrant s_ ## name ## Register(lic::ProxyFunctionVoid1<a1, name>::Register, #name)

#define LIC_REG_GLOBAL_FUNC_RET_0(name, ret)																\
	static lic::StringRegistrant s_ ## name ## Register(lic::ProxyFunctionRet0<ret, name>::Register, #name)
	
#define LIC_REG_GLOBAL_FUNC_RET_1(name, ret, a1)															\
	static lic::StringRegistrant s_ ## name ## Register(lic::ProxyFunctionRet1<								\
		ret, a1, name>::Register, #name)


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
