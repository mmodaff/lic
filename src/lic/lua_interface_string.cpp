//
// lua_interface_number.cpp - LuaInterface specializations for number types
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "lua_interface_string.h"

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
}

namespace lic
{

void LuaInterface<const char*>::Push(lua_State* pL, const char* obj)
{
	lua_pushstring(pL, obj);
}

void LuaInterface<const char*>::PushRefIfObj(lua_State* pL, const char*& obj)
{
	lua_pushstring(pL, obj);
}

const char* LuaInterface<const char*>::Get(lua_State* pL, int index, bool validate)
{
	if (validate)
			return luaL_checkstring(pL, index);
	else
		return lua_tostring(pL, index);
}

}
