//
// registrant.h - Object that takes a static function on construction and calls it when Registrant::CallRegistrants is called
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef LIC_REGISTRANT_H
#define LIC_REGISTRANT_H

struct lua_State;

namespace lic
{

class Registrant
{
public:
	typedef void (*Fn)(lua_State*);

	Registrant(Fn fn);
	virtual ~Registrant() {}

	virtual void CallRegistrant(lua_State* pL);

	static void CallRegistrants(lua_State* pL);
private:
	static Registrant* sm_pFirst;

	Registrant* m_pNext;
	Fn m_Fn;
};

}

#endif
