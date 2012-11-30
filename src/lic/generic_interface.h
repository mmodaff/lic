//
// generic_interface.h - Base classes that contains functionality common to most LuaInterface classes
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_GENERIC_INTERFACE_H
#define LIC_GENERIC_INTERFACE_H

#include <map>
#include <string>
#include "lua_wrapper.h"

struct lua_State;
typedef int (*lua_CFunction)(lua_State*);

namespace lic
{

template <typename T>
class Base
{
public:
	static int& GetRegIndex();
	static void PushMetatable(lua_State* pL);
	static LuaWrapper<T>* CreateWrapperOnTop(lua_State* pL);
	static LuaWrapper<T>* GetWrapper(lua_State* pL, int arg, bool check);
	static void PushRefIfObj(lua_State* pL, T& obj);
	static T* GetPtr(lua_State* pL, int arg, bool check);
	static void Validate(lua_State* pL, int arg);
};

template <typename T>
class GenericRegister
{
public:
	static void Register(lua_State* pL);
};

class GenericNotDerived
{
public:
	static void RegisterBase(lua_State* pL) {}
	static void PushBaseMetatable(lua_State* pL);
};

template <typename T>
class GenericDerived
{
public:
	static void RegisterBase(lua_State* pL);
	static void PushBaseMetatable(lua_State* pL);
};

struct GenericDispatchItem
{
	GenericDispatchItem(bool _accessor, lua_CFunction _func) : accessor(_accessor), func(_func) {}
	bool accessor;
	lua_CFunction func;
};

typedef std::map<std::string, GenericDispatchItem> GenericDispatchMap;
typedef std::map<std::string, lua_CFunction> GenericFunctionMap;

template <typename T>
class GenericDispatch
{
public:
	static int Dispatch(lua_State* pL);
	static int CallSetter(lua_State* pL);
	static GenericDispatchMap& GetDispatchMap();
	static GenericFunctionMap& GetSetterMap();
	static void RegisterMemberFunc(lua_State* pL, const char* pName, lua_CFunction func);
	static void RegisterMemberAccessor(lua_State* pL, const char* pName, lua_CFunction pFunc);
	static void RegisterMemberSetter(lua_State* pL, const char* pName, lua_CFunction pFunc);
};

template <typename T>
class GenericGC
{
public:
	static int GC(lua_State* pL);
};

class NoDeleteGC
{
public:
	static int GC(lua_State* pL) { return 0; }
};

template <typename T>
class GenericInterface :
	public Base<T>,
	public GenericRegister<T>,
	public GenericNotDerived,
	public GenericDispatch<T>,
	public GenericGC<T>
{
};

template <typename T, typename B>
class GenericInterfaceDerived :
	public Base<T>,
	public GenericRegister<T>,
	public GenericDerived<B>,
	public GenericDispatch<T>,
	public GenericGC<T>
{
};

template <typename T>
class GenericInterfaceSingleton :
	public Base<T>,
	public GenericRegister<T>,
	public GenericNotDerived,
	public GenericDispatch<T>,
	public NoDeleteGC
{
};

}

#endif
