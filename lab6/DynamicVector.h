#pragma once
#include "Footage.h"

template <typename TypeFootage>

class DynamicVector
{
private:
	TypeFootage * fragments;
	int capacity, numberOfFragments;
public:
	DynamicVector(int cap = 100);
	DynamicVector(const DynamicVector& copyVector);
	DynamicVector& operator=(const DynamicVector& assignVector);
	TypeFootage& operator[](int position);

	void addFootage(const TypeFootage& newFootage);
	void updateFootage(const std::string& Title, const std::string& newLocation, const std::string& newDate, int& newAccessed, const std::string& newPreview);
	int findByTitle(const std::string& Title);
	void deleteFootage(int& position);
	
	int getNumberOfFragments() const;
	TypeFootage* getAllFragments() const;
	~DynamicVector();
private:
	void resize(double factor = 2);
};

template <typename TypeFootage>
DynamicVector<TypeFootage>::DynamicVector(int cap)
{
	this->capacity = cap;
	this->numberOfFragments = 0;
	this->fragments = new TypeFootage[this->capacity];
}

template <typename TypeFootage>
DynamicVector<TypeFootage>::DynamicVector(const DynamicVector<TypeFootage> & copyVector)
{
	this->numberOfFragments = copyVector.numberOfFragments;
	this->capacity = copyVector.capacity;
	this->fragments = new TypeFootage[this->capacity];

	for (int i = 0; i < this->numberOfFragments; i++)
		this->fragments[i] = copyVector.fragments[i];
}

template <typename TypeFootage>
DynamicVector<TypeFootage>::~DynamicVector()
{
	delete[] this->fragments;
}

template <typename TypeFootage>
DynamicVector<TypeFootage> & DynamicVector<TypeFootage>::operator=(const DynamicVector<TypeFootage> & assignVector)
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

template <typename TypeFootage>
TypeFootage & DynamicVector<TypeFootage>::operator[](int position)
{
	return this->fragments[position];
}

template <typename TypeFootage>
void DynamicVector<TypeFootage>::addFootage(const TypeFootage & newFootage)
{
	if (this->numberOfFragments >= this->capacity)
		this->resize();

	this->fragments[this->numberOfFragments] = newFootage;
	this->numberOfFragments++;
	//std::cout << this->numberOfFragments << "\n";
}

template <typename TypeFootage>
void DynamicVector<TypeFootage>::updateFootage(const std::string & Title, const std::string & newLocation, const std::string & newDate, int & newAccessed, const std::string & newPreview)
{
	int position = DynamicVector<TypeFootage>::findByTitle(Title);
	this->fragments[position].setLocation(newLocation);
	this->fragments[position].setTimeOfCreation(newDate);
	this->fragments[position].setTimesAccessed(newAccessed);
	this->fragments[position].setFootagePreview(newPreview);
}

template <typename TypeFootage>
int DynamicVector<TypeFootage>::getNumberOfFragments() const
{
	return this->numberOfFragments;
}

template <typename TypeFootage>
TypeFootage * DynamicVector<TypeFootage>::getAllFragments() const
{
	return this->fragments;
}

template <typename TypeFootage>
void DynamicVector<TypeFootage>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TypeFootage* auxiliarVector = new TypeFootage[this->capacity];
	for (int i = 0; i < this->numberOfFragments; i++)
		auxiliarVector[i] = this->fragments[i];

	delete[] this->fragments;
	this->fragments = auxiliarVector;
}

template <typename TypeFootage>
int DynamicVector<TypeFootage>::findByTitle(const std::string & Title)
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

template <typename TypeFootage>
void DynamicVector<TypeFootage>::deleteFootage(int & position)
{
	//delete &this->fragments[position];
	for (int i = position; i < this->numberOfFragments - 1; i++)
		this->fragments[i] = this->fragments[i + 1];
	this->numberOfFragments--;
	//delete &this->fragments[this->numberOfFragments];
}




