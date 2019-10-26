#include "FakeRepository.h"



FakeRepository::FakeRepository()
{
}

FakeRepository::~FakeRepository()
{
}

bool FakeRepository::add(const TElem & newFootage)
{
	/*Validator::validateFootage(newFootage);
	if (this->findByTitle(newFootage.getTitle()) != -1)
	throw nameError("Title already exists");
	this->fakeList.push_back(newFootage);*/
	//cout << "called\n";
	return true;
}

TElem FakeRepository::deleteRepository(const std::string & Title)
{
	/*if (this->findByTitle(Title) == -1)
	throw nameError("Title does not exist");
	int position = this->findByTitle(Title);
	this->fakeList.erase(this->fakeList.begin() + position);*/
	return TElem();
}

TElem FakeRepository::update(const std::string & Title, const std::string & newLocation, const std::string & newDate, int & newAccessed, const std::string & newPreview)
{
	return TElem();
}

int FakeRepository::findByTitle(const std::string & Title)
{
	return 0;
}

