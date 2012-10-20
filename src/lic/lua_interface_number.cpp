//
// lua_interface_number.cpp - LuaInterface specializations for number types
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "lua_interface_number.h"

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
}

namespace lic
{

template <typename T>
void LuaInterfaceNumberBase<T>::Push(lua_State* pL, T obj)
{
	lua_pushnumber(pL, (lua_Number)obj);
}

template <typename T>
void LuaInterfaceNumberBase<T>::PushRefIfObj(lua_State* pL, T& obj)
{
	lua_pushnumber(pL, (lua_Number)obj);
}

template<typename T>
T LuaInterfaceNumberBase<T>::Get(lua_State* pL, int index, bool validate)
{
	if (validate)
		return (T)luaL_checknumber(pL, index);
	else
		return (T)lua_tonumber(pL, index);
}

template class LuaInterfaceNumberBase<int>;
template class LuaInterfaceNumberBase<unsigned int>;
template class LuaInterfaceNumberBase<char>;
template class LuaInterfaceNumberBase<unsigned char>;
template class LuaInterfaceNumberBase<long>;
template class LuaInterfaceNumberBase<unsigned long>;
template class LuaInterfaceNumberBase<long long>;
template class LuaInterfaceNumberBase<unsigned long long>;
template class LuaInterfaceNumberBase<float>;
template class LuaInterfaceNumberBase<double>;

}
