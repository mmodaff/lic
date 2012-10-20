//
// lua_interface_base.inl - contains the implemention of the templated LuaInterfaceBase class
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "lua_interface_base.h"

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
}

namespace lic
{

template<typename T>
void LuaInterfaceBase<T>::Register(lua_State* pL)
{
	if (sm_regIndex == -1)
	{
		int top = lua_gettop(pL);
		lua_newtable(pL);
		int metatable = lua_gettop(pL);

		lua_pushliteral(pL, "__index");
		lua_pushcfunction(pL, Dispatch);
		lua_rawset(pL, metatable);

		lua_pushliteral(pL, "__gc");
		lua_pushcfunction(pL, GC);
		lua_rawset(pL, metatable);

		lua_pushliteral(pL, "__newindex");
		lua_pushcfunction(pL, CallSetter);
		lua_rawset(pL, metatable);

		sm_regIndex = luaL_ref(pL, LUA_REGISTRYINDEX);
		if (lua_gettop(pL) != top)
		{
			char* pTest = 0;
			*pTest = 1;
		}
	}
}

template<typename T>
template<typename B>
void LuaInterfaceBase<T>::RegisterBase(lua_State* pL)
{
	LuaInterfaceBase<B>::Register(pL);
	PushMetatable(pL);
	lua_pushliteral(pL, "__base");
	LuaInterfaceBase<B>::PushMetatable(pL);
	lua_rawset(pL, -3);
	lua_pop(pL, 1);
}

template<typename T>
void LuaInterfaceBase<T>::PushMetatable(lua_State* pL)
{
	lua_rawgeti(pL, LUA_REGISTRYINDEX, sm_regIndex);
}

template <typename T>
int LuaInterfaceBase<T>::Dispatch(lua_State* pL)
{
	const char* pFunc = lua_tostring(pL, 2);
	DispatchMap::iterator it = sm_dispatchMap.find(pFunc);
	if (it != sm_dispatchMap.end())
	{
		if (it->second.accessor)
			it->second.func(pL);
		else
			lua_pushcfunction(pL, it->second.func);
	}
	else
	{
		PushMetatable(pL);
		lua_pushliteral(pL, "__base");
		lua_rawget(pL, -2);
		lua_remove(pL, -2);

		if (!lua_isnil(pL, -1))
		{
			lua_pushliteral(pL, "__index");
			lua_rawget(pL, -2);
			lua_remove(pL, -2);
			lua_pushvalue(pL, 1);
			lua_pushvalue(pL, 2);
			lua_call(pL, 2, 1);
		}
	}
	return 1;
}

template <typename T>
int LuaInterfaceBase<T>::CallSetter(lua_State* pL)
{
	const char* pFunc = lua_tostring(pL, 2);
	SetterMap::iterator it = sm_setterMap.find(pFunc);
	if (it != sm_setterMap.end())
	{
		it->second(pL);
	}
	else
	{
		PushMetatable(pL);
		lua_pushliteral(pL, "__base");
		lua_rawget(pL, -2);
		lua_remove(pL, -2);

		if (!lua_isnil(pL, -1))
		{
			lua_pushliteral(pL, "__newindex");
			lua_rawget(pL, -2);
			lua_remove(pL, -2);
			lua_pushvalue(pL, 1);
			lua_pushvalue(pL, 2);
			lua_pushvalue(pL, 3);
			lua_call(pL, 3, 0);
		}
	}

	return 0;
}

template <typename T>
void LuaInterfaceBase<T>::Validate(lua_State* pL, int index)
{
	if (lua_type(pL, index) != LUA_TUSERDATA)
	{
		luaL_error(pL, "Invalid argument type");
	}

	PushMetatable(pL);
	lua_getmetatable(pL, index);
	while(!lua_isnil(pL, -1))
	{
		if(lua_rawequal(pL, -1, -2))
		{
			lua_pop(pL, 2);

			if(!GetWrapper(pL, index, false)->pObj)
			{
				luaL_error(pL, "Argument is in an invalid state");
			}

			return;
		}

		lua_pushliteral(pL, "__base");
		lua_rawget(pL, -2);
		lua_remove(pL, -2);
	}

	lua_pop(pL, 2);
	luaL_error(pL, "Invalid argument type");
}

template<typename T>
T* LuaInterfaceBase<T>::GetPtr(lua_State* pL, int index, bool validate)
{
	return GetWrapper(pL, index, validate)->pObj;
}

template<typename T>
LuaWrapper<T>* LuaInterfaceBase<T>::GetWrapper(lua_State* pL, int index, bool validate)
{
	if (validate)
		Validate(pL, index);

	return (LuaWrapper<T>*)lua_touserdata(pL, index);
}

template <typename T>
int LuaInterfaceBase<T>::GC(lua_State* pL)
{
	LuaWrapper<T>* pWrap = (LuaWrapper<T>*)lua_touserdata(pL, 1);
	if (pWrap->owns)
		delete pWrap->pObj;
	pWrap->~LuaWrapper<T>();
	return 0;
}

template<typename T>
void LuaInterfaceBase<T>::RegisterMemberFunc(lua_State* pL, const char* pName, lua_CFunction pFunc)
{
	Register(pL);
	sm_dispatchMap.insert(std::make_pair(std::string(pName), DispatchItem(false, pFunc)));
}

template<typename T>
void LuaInterfaceBase<T>::RegisterMemberAccessor(lua_State* pL, const char* pName, lua_CFunction pFunc)
{
	Register(pL);
	sm_dispatchMap.insert(std::make_pair(std::string(pName), DispatchItem(true, pFunc)));
}

template<typename T>
void LuaInterfaceBase<T>::RegisterMemberSetter(lua_State* pL, const char* pName, lua_CFunction pFunc)
{
	Register(pL);
	sm_setterMap.insert(std::make_pair(std::string(pName), pFunc));
}


}
