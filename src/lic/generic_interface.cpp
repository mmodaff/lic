//
// generic_interface.cpp - Base classes that contains functionality common to most LuaInterface classes
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "generic_interface.h"

extern "C"
{
#include <lua.h>
}

namespace lic
{

void GenericNotDerived::PushBaseMetatable(lua_State* pL)
{
	lua_pushnil(pL);
}

}
