//
// lua_interface_number.h - LuaInterface specializations for number types
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_LUA_INTERFACE_NUMBER_H
#define LIC_LUA_INTERFACE_NUMBER_H

#include "lua_interface_default.h"

namespace lic
{


template <typename T>
class LuaInterfaceNumberBase
{
public:
	static void Push(lua_State* pL, T pObj);
	static void PushRefIfObj(lua_State* pL, T& obj);
	static T Get(lua_State* pL, int index, bool validate);
};

template <> class LuaInterface<char> : public LuaInterfaceNumberBase<char> {};
template <> class LuaInterface<unsigned char> : public LuaInterfaceNumberBase<unsigned char> {};
template <> class LuaInterface<short> : public LuaInterfaceNumberBase<short> {};
template <> class LuaInterface<unsigned short> : public LuaInterfaceNumberBase<unsigned short> {};
template <> class LuaInterface<int> : public LuaInterfaceNumberBase<int> {};
template <> class LuaInterface<unsigned int> : public LuaInterfaceNumberBase<unsigned int> {};
template <> class LuaInterface<long> : public LuaInterfaceNumberBase<long> {};
template <> class LuaInterface<unsigned long> : public LuaInterfaceNumberBase<unsigned long> {};
template <> class LuaInterface<long long> : public LuaInterfaceNumberBase<long long> {};
template <> class LuaInterface<unsigned long long> : public LuaInterfaceNumberBase<unsigned long long> {};
template <> class LuaInterface<float> : public LuaInterfaceNumberBase<float> {};
template <> class LuaInterface<double> : public LuaInterfaceNumberBase<double> {};

}

#endif
