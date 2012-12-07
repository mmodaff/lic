//
// generic_interface.inl - contains the implemention of the templated Generic classes
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_GENERIC_INTERFACE_INL
#define LIC_GENERIC_INTERFACE_INL

#include "generic_interface.h"
#include <new>

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
}


namespace lic
{

template <typename T>
int& Base<T>::GetRegIndex()
{
	static int s = -1;
	return s;
}

template <typename T>
void Base<T>::PushMetatable(lua_State* pL)
{
	lua_rawgeti(pL, LUA_REGISTRYINDEX, GetRegIndex());
}

template <typename T>
LuaWrapper<T>* Base<T>::CreateWrapperOnTop(lua_State* pL)
{
	LuaWrapper<T>* pData = new (lua_newuserdata(pL, sizeof(LuaWrapper<T>))) LuaWrapper<T>();
	Base::PushMetatable(pL);
	lua_setmetatable(pL, -2);

	return pData;
}

template <typename T>
void Base<T>::PushRefIfObj(lua_State* pL, T& obj)
{
	CreateWrapperOnTop(pL)->pObj = &obj;
}

template <typename T>
T ValueInterface<T>::Get(lua_State* pL, int index, bool validate)
{
	return *LuaInterface<T>::GetPtr(pL, index, validate);
}

template <typename T>
void ValueInterface<T>::Push(lua_State* pL, T obj)
{
	LuaWrapper<T>* pWrap = LuaInterface<T>::CreateWrapperOnTop(pL);
	pWrap->owns = true;
	pWrap->pObj = new T(obj);
}

template<typename T>
LuaWrapper<T>* GenericGetPtr<T>::GetWrapper(lua_State* pL, int index, bool validate)
{
	if (validate)
		Validate(pL, index);

	return (LuaWrapper<T>*)lua_touserdata(pL, index);
}

template <typename T>
T* GenericGetPtr<T>::GetPtr(lua_State* pL, int arg, bool check)
{
	return GetWrapper(pL, arg, check)->pObj;
}

template <typename T>
void GenericGetPtr<T>::Validate(lua_State* pL, int index)
{
	if (index < 0)
	{
		index = lua_gettop(pL) + index + 1;
	}

	if (lua_type(pL, index) != LUA_TUSERDATA)
	{
		luaL_error(pL, "Invalid argument type");
	}

	LuaInterface<T>::PushMetatable(pL);
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

template <typename T>
void GenericRegister<T>::Register(lua_State* pL)
{
	if (LuaInterface<T>::GetRegIndex() == -1)
	{
		LuaInterface<T>::RegisterBase(pL);

		int top = lua_gettop(pL);
		lua_newtable(pL);
		int metatable = lua_gettop(pL);

		lua_pushliteral(pL, "__gc");
		lua_pushcfunction(pL, LuaInterface<T>::GC);
		lua_rawset(pL, metatable);

		lua_pushliteral(pL, "__index");
		lua_pushcfunction(pL, LuaInterface<T>::Dispatch);
		lua_rawset(pL, metatable);

		lua_pushliteral(pL, "__newindex");
		lua_pushcfunction(pL, LuaInterface<T>::CallSetter);
		lua_rawset(pL, metatable);

		lua_pushliteral(pL, "__base");
		LuaInterface<T>::PushBaseMetatable(pL);
		lua_rawset(pL, metatable);

		LuaInterface<T>::GetRegIndex() = luaL_ref(pL, LUA_REGISTRYINDEX);
	}
}

template <typename T>
int GenericGC<T>::GC(lua_State* pL)
{
	LuaWrapper<T>* pWrap = (LuaWrapper<T>*)lua_touserdata(pL, 1);
	if (pWrap->owns)
		delete pWrap->pObj;
	pWrap->~LuaWrapper<T>();
	return 0;
}

template <typename T>
void GenericDerived<T>::PushBaseMetatable(lua_State* pL)
{
	LuaInterface<T>::PushMetatable(pL);
}

template <typename T>
void GenericDerived<T>::RegisterBase(lua_State* pL)
{
	LuaInterface<T>::Register(pL);
}

template <typename T>
int GenericDispatch<T>::Dispatch(lua_State* pL)
{
	const char* pFunc = lua_tostring(pL, 2);

	typename GenericDispatchMap::iterator it = GetDispatchMap().find(pFunc);
	if (it != GetDispatchMap().end())
	{
		if (it->second.accessor)
			it->second.func(pL);
		else
			lua_pushcfunction(pL, it->second.func);
	}
	else
	{
		LuaInterface<T>::PushMetatable(pL);
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
int GenericDispatch<T>::CallSetter(lua_State* pL)
{
	const char* pFunc = lua_tostring(pL, 2);
	GenericFunctionMap::iterator it = GetSetterMap().find(pFunc);
	if (it != GetSetterMap().end())
	{
		it->second(pL);
	}
	else
	{
		LuaInterface<T>::PushMetatable(pL);
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
GenericDispatchMap& GenericDispatch<T>::GetDispatchMap()
{
	static GenericDispatchMap s_m;
	return s_m;
}

template <typename T>
GenericFunctionMap& GenericDispatch<T>::GetSetterMap()
{
	static GenericFunctionMap s_m;
	return s_m;
}

template<typename T>
void GenericDispatch<T>::RegisterMemberFunc(lua_State* pL, const char* pName, lua_CFunction pFunc)
{
	GetDispatchMap().insert(std::make_pair(std::string(pName), GenericDispatchItem(false, pFunc)));
}

template<typename T>
void GenericDispatch<T>::RegisterMemberAccessor(lua_State* pL, const char* pName, lua_CFunction pFunc)
{
	GetDispatchMap().insert(std::make_pair(std::string(pName), GenericDispatchItem(true, pFunc)));
}

template<typename T>
void GenericDispatch<T>::RegisterMemberSetter(lua_State* pL, const char* pName, lua_CFunction pFunc)
{
	GetSetterMap().insert(std::make_pair(std::string(pName), pFunc));
}

template<typename T>
void GenericDispatch<T>::RegisterOperator(lua_State* pL, lua_CFunction pFunc, const char* pOp)
{
	LuaInterface<T>::Register(pL);

	LuaInterface<T>::PushMetatable(pL);
	lua_pushstring(pL, pOp);
	lua_pushcfunction(pL, pFunc);
	lua_rawset(pL, -3);
	lua_pop(pL, 1);
}

}

#endif
