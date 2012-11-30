//
// proxy_class_member.inl - Templated lua functions get/set public members
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_PROXY_CLASS_MEMBER_INL
#define LIC_PROXY_CLASS_MEMBER_INL

#include "proxy_class_member.h"
#include "lua_interface.h"

struct lua_State;

namespace lic
{

template <typename T, typename M, M T::*Member>
void ProxyClassMemberGetter<T, M, Member>::Register(lua_State* pL, const char* pName)
{
	LuaInterface<T>::RegisterMemberAccessor(pL, pName, Get);
}

template <typename T, typename M, M T::*Member>
int ProxyClassMemberGetter<T, M, Member>::Get(lua_State* pL)
{
	LuaInterface<M>::PushRefIfObj(pL, LuaInterface<T*>::Get(pL, 1, true)->*Member);
	return 1;
}

template <typename T, typename M, M T::*Member>
void ProxyClassMember<T, M, Member>::Register(lua_State* pL, const char* pName)
{
	LuaInterface<T>::RegisterMemberAccessor(pL, pName, Get);
	LuaInterface<T>::RegisterMemberSetter(pL, pName, Set);
}

template <typename T, typename M, M T::*Member>
int ProxyClassMember<T, M, Member>::Set(lua_State* pL)
{
	LuaInterface<T*>::Get(pL, 1, true)->*Member = LuaInterface<M>::Get(pL, 3, true);
	return 0;
}

}

#endif
