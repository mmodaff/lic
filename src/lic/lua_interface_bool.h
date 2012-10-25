//
// lua_interface_bool.h - LuaInterface specializations for bool
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_LUA_INTERFACE_BOOL_H
#define LIC_LUA_INTERFACE_BOOL_H

#include "lua_interface_default.h"

namespace lic
{


template <>
class LuaInterface<bool>
{
public:
	static void Push(lua_State* pL, bool pObj);
	static void PushRefIfObj(lua_State* pL, bool& obj);
	static bool Get(lua_State* pL, int index, bool validate);
};

}

#endif
