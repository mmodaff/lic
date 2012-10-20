//
// util.h - Utility functions
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_UTIL_H
#define LIC_UTIL_H

struct lua_State;

namespace lic
{

void ValidateNumArgs(lua_State* pL, int args);
void ValidateMinArgs(lua_State* pL, int min);

}

#endif
