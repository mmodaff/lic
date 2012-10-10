//
// proxy_function.h - Templated lua functions that call out to other functions
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_PROXY_FUNCTION_H
#define LIC_PROXY_FUNCTION_H

struct lua_State;

namespace lic
{

template <void (*Fn)()>
int ProxyFunctionVoid(lua_State* pL);

template <typename A1, void(*Fn)(A1)>
int ProxyFunctionVoid(lua_State* pL);

template <typename A1, typename A2, void(*Fn)(A1, A2)>
int ProxyFunctionVoid(lua_State* pL);

template <typename A1, typename A2, typename A3, void(*Fn)(A1, A2, A3)>
int ProxyFunctionVoid(lua_State* pL);

template <typename A1, typename A2, typename A3, typename A4, void(*Fn)(A1, A2, A3, A4)>
int ProxyFunctionVoid(lua_State* pL);

template <typename A1, typename A2, typename A3, typename A4, typename A5, void(*Fn)(A1, A2, A3, A4, A5)>
int ProxyFunctionVoid(lua_State* pL);

template <typename Ret, Ret (*Fn)()>
int ProxyFunctionRet(lua_State* pL);

template <typename Ret, typename A1, Ret (*Fn)(A1)>
int ProxyFunctionRet(lua_State* pL);

template <typename Ret, typename A1, typename A2, Ret (*Fn)(A1, A2)>
int ProxyFunctionRet(lua_State* pL);

template <typename Ret, typename A1, typename A2, typename A3, Ret (*Fn)(A1, A2, A3)>
int ProxyFunctionRet(lua_State* pL);

template <typename Ret, typename A1, typename A2, typename A3, typename A4, Ret (*Fn)(A1, A2, A3, A4)>
int ProxyFunctionRet(lua_State* pL);

template <typename Ret, typename A1, typename A2, typename A3, typename A4, typename A5, Ret (*Fn)(A1, A2, A3, A4, A5)>
int ProxyFunctionRet(lua_State* pL);
}

#endif
