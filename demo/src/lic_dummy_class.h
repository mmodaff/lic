//
// lic_dummy_class.h - macros to expose DummyClass
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_DUMMY_CLASS_H
#define LIC_DUMMY_CLASS_H

#include <lic/generic_interface.h>
#include <lic/lua_interface.h>

namespace demo
{

class DummyClass;

}

namespace lic
{

template <>
class LuaInterface<demo::DummyClass> : public GenericInterface<demo::DummyClass>
{
};

}

#endif
