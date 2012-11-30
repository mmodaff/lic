//
// lic_derived_class.h - macros to expose DerivedClass
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_DERIVED_CLASS_H
#define LIC_DERIVED_CLASS_H

#include "lic_dummy_class.h"
#include <lic/generic_interface.h>
#include <lic/lua_interface.h>

namespace demo
{

class DerivedClass;

}

namespace lic
{

template <>
class LuaInterface<demo::DerivedClass> : public GenericInterfaceDerived<demo::DerivedClass, demo::DummyClass>
{
};

}

#endif
