//
// derived_class.h - class exposed to script
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef DEMO_DERIVED_CLASS_H
#define DEMO_DERIVED_CLASS_H

#include "dummy_class.h"

namespace demo
{

class DerivedClass : public DummyClass
{
public:
	DerivedClass(int y);
	virtual ~DerivedClass();

	void SetY(int y);
	int GetY();

	void PrintY();

private:
	int m_y;
};

}

#endif
