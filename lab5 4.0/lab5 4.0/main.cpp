// lab5 4.0.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "UI.h"
//#include "Tests.h"


int main()
{
	Repository repo;
	ControllerA controller{ repo };
	UI ui{ controller };
	ui.run();
	//Tests tests{};
	//tests.runTests();
	return 0;
}

