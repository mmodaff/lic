//
// lua_interface.h - Templated class that handles most of the interface responsibilities
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_LUA_INTERFACE_H
#define LIC_LUA_INTERFACE_H

struct lua_State;

namespace lic
{

template <typename T>
class LuaInterface
{
public:
#if 0
	static void PushRefIfObj(lua_State* pL, T& obj);
	static void Push(lua_State* pL, T obj);
	static T Get(lua_State* pL, int arg, bool check = true);
	static T* GetPtr(lua_State* pL, int arg, bool check);
#endif
};

template <typename T>
class LuaInterface<T*> 
{
public:
	typedef LuaInterface<T> Base;

	static void Push(lua_State* pL, T* pObj, bool owns = false);
	static T* Get(lua_State* pL, int index, bool validate);
	static T* GetPtr(lua_State* pL, int index, bool validate);
};

template <typename T>
class LuaInterface<T&>
{
public:
	typedef LuaInterface<T> Base;

	static void Push(lua_State* pL, T& obj);
	static T& Get(lua_State* pL, int index, bool validate);
	static T* GetPtr(lua_State* pL, int index, bool validate);
};

template <typename T>
class LuaInterface<const T&>
{
public:
	typedef LuaInterface<T> Base;

	static void Push(lua_State* pL, const T& obj);
	static const T& Get(lua_State* pL, int index, bool validate);
	static const T* GetPtr(lua_State* pL, int index, bool validate);
};

}

#endif
