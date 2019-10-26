#include "Repository.h"


void Repository::add(const Footage & newFootage)
{
	this->elements.addFootage(newFootage);
}

void Repository::update(const std::string & Title, const std::string & newLocation, const std::string & newDate, int & newAccessed, const std::string & newPreview)
{
	this->elements.updateFootage(Title, newLocation, newDate, newAccessed, newPreview);
}

void Repository::deleteRepository(int & position)
{
	this->elements.deleteFootage(position);
}

void Repository::initialization()
{
	std::string title = "title";
	std::string location = "location";
	std::string timeOfCreation = "10-05-2543";
	std::string footagePreview = "preview";
	int timesAccessed = 6;
	TElem newFootage = TElem(title, location, timeOfCreation, timesAccessed, footagePreview);
	this->add(newFootage);

	std::string title2 = "title2";
	std::string location2 = "location2";
	std::string timeOfCreation2 = "05-12-2043";
	std::string footagePreview2 = "preview2";
	int timesAccessed2 = 3;
	TElem newFootage2 = TElem(title2, location2, timeOfCreation2, timesAccessed2, footagePreview2);
	this->add(newFootage2);

	std::string title3 = "newTitle";
	std::string location3 = "newLocation";
	std::string timeOfCreation3 = "15-08-1257";
	std::string footagePreview3 = "newPreview";
	int timesAccessed3 = 7;
	TElem newFootage3 = TElem(title3, location3, timeOfCreation3, timesAccessed3, footagePreview3);
	this->add(newFootage3);
}

//TElem &Repository::operator[](int position)
//{
//	return this->elements[position];
//}

Repository::~Repository()
{
}
