//
// dummy_class.cpp - class exposed to script
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "dummy_class.h"
#include <stdio.h>

namespace demo
{

DummyClass::DummyClass() : m_x(0)
{
}

DummyClass::~DummyClass()
{
	printf("DummyClass destroyed\n");
}

void DummyClass::SetX(int x)
{
	m_x = x;
}

int DummyClass::GetX()
{
	return m_x;
}

void DummyClass::PrintX()
{
	printf("X: %d\n", m_x);
}

}
