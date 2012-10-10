//
// string_registrant.cpp - registrant that takes a string as a second argument; set at registrant creation time
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "string_registrant.h"

#include <string.h>

namespace lic
{

StringRegistrant::StringRegistrant(StrFn fn, const char* pString) :
	Registrant(0),
	m_strFn(fn)
{
	m_pString = new char[strlen(pString) + 1];
	strcpy(m_pString, pString);
}

StringRegistrant::~StringRegistrant()
{
	delete[] m_pString;
}

void StringRegistrant::CallRegistrant(lua_State* pL)
{
	m_strFn(pL, m_pString);
}

}
