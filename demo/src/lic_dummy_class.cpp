//
// lic_dummy_class.cpp - macros to expose DummyClass
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "dummy_class.h"
#include <lic/register_class_macros.h>

using namespace demo;

LIC_REG_CLASS(DummyClass);
LIC_REG_CLASS_CTOR_0(DummyClass);
LIC_REG_CLASS_FUNC_VOID_0(DummyClass, PrintX);
LIC_REG_CLASS_FUNC_VOID_1(DummyClass, SetX, int);
LIC_REG_CLASS_FUNC_RET_0(DummyClass, GetX, int);
