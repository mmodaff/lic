//
// string_registrant.h - registrant that takes a string as a second argument; set at registrant creation time
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_STRING_REGISTRANT_H
#define LIC_STRING_REGISTRANT_H

#include "registrant.h"

struct lua_State;

namespace lic
{

class StringRegistrant : public Registrant
{
public:
	typedef void (*StrFn)(lua_State*, const char*);

	StringRegistrant(StrFn fn, const char* pString);
	virtual ~StringRegistrant();

	virtual void CallRegistrant(lua_State* pL);

private:
	char* m_pString;
	StrFn m_strFn;
};

}

#endif
