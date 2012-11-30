//
// lic_global_funcs.cpp - macros to expose the funcs in global_funcs.h
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "global_funcs.h"
#include <lic/lua_interface_number.h>
#include <lic/register_global_macros.h>

using namespace demo;

LIC_REG_GLOBAL_FUNC_VOID_0(PrintLic);
LIC_REG_GLOBAL_FUNC_VOID_1(PrintString, const char*);
LIC_REG_GLOBAL_FUNC_RET_0(Return0, int);
LIC_REG_GLOBAL_FUNC_RET_1(AddOne, int, int);
