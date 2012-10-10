//
// registrant.cpp - Object that takes a static function on construction and calls it when Registrant::CallRegistrants is called
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "registrant.h"

namespace lic
{

Registrant* Registrant::sm_pFirst = 0;

Registrant::Registrant(Fn fn) :
	m_Fn(fn)
{
	m_pNext = sm_pFirst;
	sm_pFirst = this;
}

void Registrant::CallRegistrant(lua_State* pL)
{
	m_Fn(pL);
}
	
void Registrant::CallRegistrants(lua_State* pL)
{
	Registrant* pCurr = sm_pFirst;
	while (pCurr)
	{
		pCurr->CallRegistrant(pL);
		pCurr = pCurr->m_pNext;
	}
}

}
