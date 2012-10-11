//
// global_funcs.cpp - loose functions that will get registered as globals
// Copyright 2012 Matt Modaff
//
// See the LICENSE file for license details
//

#include "global_funcs.h"
#include <stdio.h>

namespace demo
{

void PrintLic()
{
	printf("LIC\n");
}

void PrintString(const char* a)
{
	printf("%s\n", a);
}

int Return0()
{
	return 0;
}

int AddOne(int a)
{
	return a + 1;
}

}
