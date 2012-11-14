//
// lic_derived_class.cpp - macros to expose DerivedClass
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "derived_class.h"
#include <lic/register_class_macros.h>

using namespace demo;

LIC_REG_DERIVED_CLASS(DerivedClass, DummyClass);
LIC_REG_CLASS_CTOR_1(DerivedClass, true, int);
LIC_REG_CLASS_FUNC_VOID_0(DerivedClass, PrintY);
LIC_REG_CLASS_FUNC_VOID_1(DerivedClass, SetY, int);
LIC_REG_CLASS_FUNC_RET_0(DerivedClass, GetY, int);
