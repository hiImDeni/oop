#include "DynamicVector.h"



DynamicVector::DynamicVector(int cap)
{
	this->capacity = cap;
	this->numberOfFragments = 0;
	this->fragments = new TElem[this->capacity];
}

DynamicVector::DynamicVector(const DynamicVector & copyVector)
{
	this->numberOfFragments = copyVector.numberOfFragments;
	this->capacity = copyVector.capacity;
	this->fragments = new TElem[this->capacity];

	for (int i = 0; i < this->numberOfFragments; i++)
		this->fragments[i] = copyVector.fragments[i];
}

DynamicVector & DynamicVector::operator=(const DynamicVector & assignVector)
{
	if (this == &assignVector)
		return *this;

	this->numberOfFragments = assignVector.numberOfFragments;
	this->capacity = assignVector.capacity;
	delete[] this->fragments;

	for (int i = 0; i < this->numberOfFragments; i++)
		this->fragments[i] = assignVector.fragments[i];

	return *this;
}

TElem & DynamicVector::operator[](int position)
{
	return this->fragments[position];
}

void DynamicVector::addFootage(const TElem & newFootage)
{
	if (this->numberOfFragments >= this->capacity)
		this->resize();

	this->fragments[this->numberOfFragments] = newFootage;
	this->numberOfFragments++;
	//std::cout << this->numberOfFragments << "\n";
}

void DynamicVector::updateFootage(const std::string & Title, const std::string & newLocation, const std::string & newDate, int & newAccessed, const std::string & newPreview)
{
	int position = DynamicVector::findByTitle(Title);
	this->fragments[position].setLocation(newLocation);
	this->fragments[position].setTimeOfCreation(newDate);
	this->fragments[position].setTimesAccessed(newAccessed);
	this->fragments[position].setFootagePreview(newPreview);
}


int DynamicVector::getNumberOfFragments() const
{
	return this->numberOfFragments;
}

TElem * DynamicVector::getAllFragments() const
{
	return this->fragments;
}

DynamicVector::~DynamicVector()
{
	delete[] this->fragments;
}

void DynamicVector::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TElem* auxiliarVector = new TElem[this->capacity];
	for (int i = 0; i < this->numberOfFragments; i++)
		auxiliarVector[i] = this->fragments[i];

	delete[] this->fragments;
	this->fragments = auxiliarVector;
}

int DynamicVector::findByTitle(const std::string & Title)
{
	int position = -1;
	for (int i = 0; i < this->numberOfFragments; i++)
		if (this->fragments[i].getTitle() == Title)
		{
			position = i;
			break;
		}
	return position;
}

void DynamicVector::deleteFootage(int & position)
{
	//delete &this->fragments[position];
	for (int i = position; i < this->numberOfFragments-1; i++)
		this->fragments[i] = this->fragments[i + 1];
	this->numberOfFragments--;
	//delete &this->fragments[this->numberOfFragments];
}
