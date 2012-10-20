//
// lua_interface_base.h - Base class that contains functionality common to all LuaInterface classes
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_LUA_INTERFACE_BASE_H
#define LIC_LUA_INTERFACE_BASE_H

#include <map>
#include <string>

#include "lua_wrapper.h"

struct lua_State;
typedef int (*lua_CFunction)(lua_State*);

namespace lic
{

template <typename T>
class LuaInterfaceBase
{
public:
	static void Register(lua_State* pL);
	template <typename B>
	static void RegisterBase(lua_State* pL);

	static void PushMetatable(lua_State* pL);
	static void Validate(lua_State* pL, int index);
	static T* GetPtr(lua_State* pL, int index, bool validate);
	static LuaWrapper<T>* GetWrapper(lua_State* pL, int index, bool validate);
	static int GC(lua_State* pL);

	static void RegisterMemberFunc(lua_State* pL, const char* pName, lua_CFunction pFunc);
	static void RegisterMemberAccessor(lua_State* pL, const char* pName, lua_CFunction pFunc);
	static void RegisterMemberSetter(lua_State* pL, const char* pName, lua_CFunction pFunc);

protected:
	
	static int Dispatch(lua_State* pL);
	static int CallSetter(lua_State* pL);
	struct DispatchItem
	{
		DispatchItem(bool _accessor, lua_CFunction _func) : accessor(_accessor), func(_func) {}
		bool accessor;
		lua_CFunction func;
	};
	typedef std::map<std::string, DispatchItem> DispatchMap;
	typedef std::map<std::string, lua_CFunction> SetterMap;

	static DispatchMap sm_dispatchMap;
	static SetterMap sm_setterMap;
	static int sm_regIndex;
};

}

#endif
