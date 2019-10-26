#include "Repository.h"
#include "exceptions.h"


bool Repository::add(const Footage & newFootage)
{
	Validator::validateFootage(newFootage);
	if (this->findByTitle(newFootage.getTitle()) != -1)
		throw nameError("Title already exists");
	this->elements.push_back(newFootage);
	return true;
	//this->storeData();
}


TElem Repository::update(const std::string & Title, const std::string & newLocation, const std::string & newDate, int & newAccessed, const std::string & newPreview)
{
	Validator::validateFootage(Footage(Title, newLocation, newDate, newAccessed, newPreview));
	if (this->findByTitle(Title) == -1)
		throw nameError("Title does not exist");
	for (auto& footage : this->elements)
		if (footage.getTitle() == Title)
		{
			TElem beforeUpdate = footage;
			footage.setLocation(newLocation);
			footage.setTimesAccessed(newAccessed);
			footage.setTimeOfCreation(newDate);
			footage.setFootagePreview(newPreview);
			return beforeUpdate;
		}
	//this->storeData();
}

TElem Repository::deleteRepository(const std::string & Title)
{
	if (this->findByTitle(Title) == -1)
		throw nameError("Title does not exist");
	int position = this->findByTitle(Title);
	TElem deletedFootage = elements[position];
	this->elements.erase(this->elements.begin() + position);
	return deletedFootage;
	//this->storeData();
}


Repository::Repository()
{
	//this->initialization();
}

int Repository::findByTitle(const std::string & Title)
{
	int position = -1;
	for (auto index = 0; index < this->elements.size(); index++)
		if (this->elements[index].getTitle() == Title)
		{
			position = index;
			break;
		}
	return position;
}

//void Repository::initialization()
//{
//	std::string title = "title";
//	std::string location = "location";
//	std::string timeOfCreation = "10-05-2543";
//	std::string footagePreview = "preview";
//	int timesAccessed = 6;
//	TElem newFootage = TElem(title, location, timeOfCreation, timesAccessed, footagePreview);
//	this->add(newFootage);
//
//	std::string title2 = "title2";
//	std::string location2 = "location2";
//	std::string timeOfCreation2 = "05-12-2043";
//	std::string footagePreview2 = "preview2";
//	int timesAccessed2 = 3;
//	TElem newFootage2 = TElem(title2, location2, timeOfCreation2, timesAccessed2, footagePreview2);
//	this->add(newFootage2);
//
//	std::string title3 = "newTitle";
//	std::string location3 = "newLocation";
//	std::string timeOfCreation3 = "15-08-1257";
//	std::string footagePreview3 = "newPreview";
//	int timesAccessed3 = 7;
//	TElem newFootage3 = TElem(title3, location3, timeOfCreation3, timesAccessed3, footagePreview3);
//	this->add(newFootage3);
//}


Repository::~Repository()
{
}
