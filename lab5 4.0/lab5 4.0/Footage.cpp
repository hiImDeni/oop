#include "Footage.h"
#include <iostream>


Footage::Footage(): title( "" ), location( "" ), timeOfCreation( "" ), timesAccessed( 0 ), footagePreview( "" ) {}


Footage::Footage(const std::string & Title, const std::string & Location, const std::string & Date, int& Accessed, const std::string & Preview)
{
	this->title = Title;
	this->location = Location;
	this->timeOfCreation = Date;
	this->timesAccessed = Accessed;
	this->footagePreview = Preview;
}


Footage::~Footage()
{
}
