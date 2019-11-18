#pragma once
#include "ControllerA.h"

class UI
{
private:
	ControllerA controller;
public:
	UI(const ControllerA Controller): controller(Controller) {}

	void run();
	~UI();
private:
	void addUI(const std::string & Title, const std::string & Location, const std::string & Date, int & Accessed, const std::string & Preview);
	void updateUI(const std::string & Title, const std::string & newLocation, const std::string & newDate, int & newAccessed, const std::string & newPreview);
	void deleteUI(const std::string & Title);
	
	static void printMenu();
	static void splitCommands(std::string parameters[], std::string& command, int& counter, size_t& position);
	void list();
};

