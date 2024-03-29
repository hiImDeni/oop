// lab5 4.0.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "UI.h"
#include "UIB.h"
//#include "Tests.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	cout << "Choose mode: ";
	string mode;
	getline(std::cin, mode);
	if (mode == "exit")
		return 0;
	while (mode != "mode A" and mode != "mode B")
	{
		cout << "Incorrect option.\nChoose mode: ";
		getline(cin, mode);
		if (mode == "exit")
			return 0;
	}
	Repository repo;
	//repo.initialization();
	ControllerA controller{ repo };
	if (mode == "mode A")
	{
		UI ui{ controller };
		ui.run();
	}
	else
	{
		//ControllerB controller{ repo };
		UIB ui{ controller };
		ui.run();
	}
	//Tests tests{};
	//tests.runTests();
	return 0;
}

