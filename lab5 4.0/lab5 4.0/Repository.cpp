#include "Repository.h"


void Repository::add(const TElem & newFootage)
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

//TElem &Repository::operator[](int position)
//{
//	return this->elements[position];
//}

Repository::~Repository()
{
}
