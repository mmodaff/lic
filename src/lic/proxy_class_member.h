//
// proxy_class_member.h - Templated lua functions get/set public members
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_PROXY_CLASS_MEMBER_H
#define LIC_PROXY_CLASS_MEMBER_H

struct lua_State;

namespace lic
{

template <typename T, typename M, M T::*Member>
class ProxyClassMember
{
public:
	static void Register(lua_State* pL, const char* pName);
	static int Get(lua_State* pL);
	static int Set(lua_State* pL);
};

}

#endif
