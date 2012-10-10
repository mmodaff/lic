//
// main.cpp - Run the demo
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include <iostream>
#include <lic/lic.h>

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

int main()
{
	lua_State* pL = lua_open();
	lua_cpcall(pL, luaopen_base, NULL);

	lic::Register(pL);

	if (luaL_dofile(pL, "demo.lua"))
	{
		printf("%s\n", lua_tostring(pL, -1));
	}

	lua_close(pL);
	system("pause");
	return 0;
}
