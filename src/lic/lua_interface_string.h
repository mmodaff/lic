//
// lua_interface_string.h - LuaInterface specializations for string types
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_LUA_INTERFACE_STRING_H
#define LIC_LUA_INTERFACE_STRING_H

#include "lua_interface_default.h"

namespace lic
{


template <> class LuaInterface<const char*>
{
public:
	static void Push(lua_State* pL, const char* obj);
	static void PushRefIfObj(lua_State* pL, const char*& obj);
	static const char* Get(lua_State* pL, int index, bool validate);
};

}

#endif
