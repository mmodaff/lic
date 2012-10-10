//
// derived_class.cpp - class exposed to script
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "derived_class.h"
#include <stdio.h>

namespace demo
{

DerivedClass::DerivedClass(int y) :
	DummyClass(),
	m_y(y)
{
}

DerivedClass::~DerivedClass()
{
	printf("DerivedClass destroyed.\n");
}

void DerivedClass::SetY(int y)
{
	m_y = y;
}

int DerivedClass::GetY()
{
	return m_y;
}

void DerivedClass::PrintY()
{
	printf("Y: %d\n", m_y);
}


}
