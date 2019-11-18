#pragma once
#include "Repository.h"

class ControllerA
{
private:
	Repository repository;
public:
	ControllerA(Repository& repo) : repository{ repo } {}

	//Repository& getRepository() const { return repository; }

	Repository getRepository() const { return repository; }

	void addController(const std::string& Title, const std::string& Location, const std::string& Date, int& Accessed, const std::string& Preview);
	void updateController(const std::string & Title, const std::string & newLocation, const std::string & newDate, int & newAccessed, const std::string & newPreview);
	void deleteController(int& position);
	
	~ControllerA();
};

