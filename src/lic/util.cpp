//
// util.cpp - Utility functions
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "util.h"
extern "C"
{
#include <lua.h>
#include <lauxlib.h>
}

namespace lic
{

void ValidateNumArgs(lua_State* pL, int args)
{
	if (lua_gettop(pL) != args)
		luaL_error(pL, "Invalid number of arguments.");
}

void ValidateMinArgs(lua_State* pL, int min)
{
	if (lua_gettop(pL) < min)
		luaL_error(pL, "Invalid number of arguments.");
}

}
