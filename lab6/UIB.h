#pragma once
#include "ControllerA.h"
#include "DynamicVector.h"


class UIB
{
private:
	ControllerA controller;
	DynamicVector<TElem> myList;
public:
	UIB(const ControllerA Controller) : controller(Controller) {}

	void run();

	~UIB();

private:
	void changeMode();
	static void printMenu();
	static void splitCommands(std::string parameters[], std::string& command, int& counter);
	static void printFootage(TElem& footage);
	void list();
	void printLocation(std::string& location, int& timesAccessed);
};

