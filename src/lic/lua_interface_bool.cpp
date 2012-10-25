//
// lua_interface_bool.cpp - LuaInterface specializations for bool
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "lua_interface_bool.h"

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
}

namespace lic
{

void LuaInterface<bool>::Push(lua_State* pL, bool obj)
{
	lua_pushboolean(pL, obj);
}

void LuaInterface<bool>::PushRefIfObj(lua_State* pL, bool& obj)
{
	lua_pushboolean(pL, obj);
}

bool LuaInterface<bool>::Get(lua_State* pL, int index, bool validate)
{
	if (validate)
	{
		if (!lua_isboolean(pL, index))
			luaL_error(pL, "Invalid argument");
	}

	return lua_toboolean(pL, index);
}

}
