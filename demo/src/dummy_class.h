//
// dummy_class.h - class exposed to script
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#ifndef DEMO_DUMMY_CLASS_H
#define DEMO_DUMMY_CLASS_H

namespace demo
{

class DummyClass
{
public:
	DummyClass();
	virtual ~DummyClass();

	void SetX(int x);
	int GetX();

	void PrintX();

	int Z;
private:
	int m_x;
};

}

#endif
