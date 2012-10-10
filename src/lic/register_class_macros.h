//
// register_class_macros.h - Macros to make registering class functions easier
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_REGISTER_CLASS_MACROS_H
#define LIC_REGISTER_CLASS_MACROS_H

#include "string_registrant.h"
#include "lua_interface.inl"
#include "proxy_class_ctor.inl"
#include "proxy_class_function.inl"

#define LIC_REG_CLASS(name)																					\
	template class lic::LuaInterface<name*>;																\
	template<> int lic::LuaInterfaceBase<name>::sm_regIndex = -1;											\
	template<> lic::LuaInterfaceBase<name>::DispatchMap lic::LuaInterfaceBase<name>::sm_dispatchMap =		\
		lic::LuaInterfaceBase<name>::DispatchMap();															\
	static lic::Registrant s_ ## name ## Reg(lic::LuaInterface<name*>::Register)

#define LIC_REG_CLASS_FUNC_VOID_0(T, name)																					\
	static lic::StringRegistrant s_ ## T ## name ## Reg(lic::ProxyClassFunctionVoid0<T, &T::name>::Register, #name)

#define LIC_REG_CLASS_FUNC_VOID_1(T, name, a1)																				\
	static lic::StringRegistrant s_ ## T ## name ## Reg(lic::ProxyClassFunctionVoid1<T, a1, &T::name>::Register, #name)

#define LIC_REG_CLASS_CONST_FUNC_RET_0(T, name, ret)																		\
	static lic::StringRegistrant s_ ## T ## name ## Reg(lic::ProxyClassConstFunctionRet0<T, ret, &T::name>::Register, #name)

#define LIC_REG_CLASS_DELETE_FUNC(T, name)																					\
	static lic::StringRegistrant s ## name ## Reg(lic::ProxyClassDelete<T>::Register, #name)


#endif
