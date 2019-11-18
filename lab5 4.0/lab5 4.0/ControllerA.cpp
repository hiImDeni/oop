#include "ControllerA.h"	


void ControllerA::addController(const std::string & Title, const std::string & Location, const std::string & Date, int & Accessed, const std::string & Preview)
{
	Footage newFootage{ Title, Location, Date, Accessed, Preview };
	this->repository.add(newFootage);
}

void ControllerA::updateController(const std::string & Title, const std::string & newLocation, const std::string & newDate, int & newAccessed, const std::string & newPreview)
{
	this->repository.update(Title, newLocation, newDate, newAccessed, newPreview);
}

void ControllerA::deleteController(int & position)
{
	this->repository.deleteRepository(position);
}

ControllerA::~ControllerA()
{
}
