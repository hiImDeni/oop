#pragma once
#include "Repository.h"

class ControllerA
{
	friend class UI;
	friend class Tests;
private:
	Repository repository;
public:
	ControllerA(Repository& repo) : repository{ repo } {}

	//Repository& getRepository() const { return repository; }

	Repository getRepository() const { return repository; }

	DynamicVector<Footage> getControllerElements() const { return this->repository.getElements(); }

	~ControllerA();

private:
	void addController(const std::string& Title, const std::string& Location, const std::string& Date, int& Accessed, const std::string& Preview);
	void updateController(const std::string & Title, const std::string & newLocation, const std::string & newDate, int & newAccessed, const std::string & newPreview);
	void deleteController(int& position);
	
};

