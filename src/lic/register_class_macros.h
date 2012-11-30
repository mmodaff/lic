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
#include "proxy_class_member.inl"

#define LIC_REG_CLASS(name)																					\
	static lic::Registrant s_ ## name ## Reg(lic::LuaInterface<name>::Register)

#define LIC_REG_CLASS_CTOR_0(name, owns)																			\
	lic::StringRegistrant s_ ## name ## CtorReg(lic::ProxyClassCtor0<name, owns>::Register, #name)

#define LIC_REG_CLASS_CTOR_1(name, owns, a1)																		\
	lic::StringRegistrant s_ ## name ## CtorReg(lic::ProxyClassCtor1<name, owns, a1>::Register, #name)

#define LIC_REG_CLASS_CTOR_2(name, owns, a1, a2)																	\
	lic::StringRegistrant s_ ## name ## CtorReg(lic::ProxyClassCtor2<name, owns, a1, a2>::Register, #name)

#define LIC_REG_CLASS_CTOR_3(name, owns, a1, a2, a3)																\
	lic::StringRegistrant s_ ## name ## CtorReg(lic::ProxyClassCtor3<name, owns, a1, a2, a3>::Register, #name)

#define LIC_REG_CLASS_CTOR_4(name, owns, a1, a2, a3, a4)															\
	lic::StringRegistrant s_ ## name ## CtorReg(lic::ProxyClassCtor4<name, owns, a1, a2, a3, a4>::Register, #name)

#define LIC_REG_CLASS_FUNC_LUA(T, name)																						\
	static lic::StringRegistrant s_ ## T ## name ## Reg(lic::ProxyClassFunctionLua<T, &T::name>::Register, #name)

#define LIC_REG_CLASS_FUNC_VOID_0(T, name)																					\
	static lic::StringRegistrant s_ ## T ## name ## Reg(lic::ProxyClassFunctionVoid0<T, &T::name>::Register, #name)

#define LIC_REG_CLASS_FUNC_VOID_1(T, name, a1)																				\
	static lic::StringRegistrant s_ ## T ## name ## Reg(lic::ProxyClassFunctionVoid1<T, a1, &T::name>::Register, #name)

#define LIC_REG_CLASS_FUNC_VOID_2(T, name, a1, a2)																				\
	static lic::StringRegistrant s_ ## T ## name ## Reg(lic::ProxyClassFunctionVoid2<T, a1, a2, &T::name>::Register, #name)

#define LIC_REG_CLASS_FUNC_RET_0(T, name, ret)																		\
	static lic::StringRegistrant s_ ## T ## name ## Reg(lic::ProxyClassFunctionRet0<T, ret, &T::name>::Register, #name)

#define LIC_REG_CLASS_FUNC_RET_1(T, name, ret, a1)																			\
	static lic::StringRegistrant s_ ## T ## name ## Reg(lic::ProxyClassFunctionRet1<T, ret, a1, &T::name>::Register, #name)

#define LIC_REG_CLASS_FUNC_RET_2(T, name, ret, a1, a2)																			\
	static lic::StringRegistrant s_ ## T ## name ## Reg(lic::ProxyClassFunctionRet2<T, ret, a1, a2, &T::name>::Register, #name)

#define LIC_REG_CLASS_CONST_FUNC_RET_0(T, name, ret)																		\
	static lic::StringRegistrant s_ ## T ## name ## Reg(lic::ProxyClassConstFunctionRet0<T, ret, &T::name>::Register, #name)

#define LIC_REG_CLASS_DELETE_FUNC(T, name)																					\
	static lic::StringRegistrant s_ ## name ## DeleteReg(lic::ProxyClassDelete<T>::Register, #name)

#define LIC_REG_CLASS_MEMBER(T, name, type)																					\
	static lic::StringRegistrant s_ ## T ## name ## Reg(lic::ProxyClassMember<T, type, &T::name>::Register, #name)

#define LIC_REG_CLASS_MEMBER_GETTER(T, name, type)																					\
	static lic::StringRegistrant s_ ## T ## name ## Reg(lic::ProxyClassMemberGetter<T, type, &T::name>::Register, #name)

#endif
