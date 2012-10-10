//
// lic.h - Entry point to the lic library
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_LIC_H
#define LIC_LIC_H

#include "registrant.h"

struct lua_State;

namespace lic
{

inline void Register(lua_State* pL)
{
	Registrant::CallRegistrants(pL);
}

}

#endif
