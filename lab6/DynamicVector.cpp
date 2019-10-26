#include "DynamicVector.h"

//template <typename TElem>
//DynamicVector<TElem>::DynamicVector(int cap)
//{
//	this->capacity = cap;
//	this->numberOfFragments = 0;
//	this->fragments = new TElem[this->capacity];
//}

//template <typename TElem>
//DynamicVector<TElem>::DynamicVector(const DynamicVector<TElem> & copyVector)
//{
//	this->numberOfFragments = copyVector.numberOfFragments;
//	this->capacity = copyVector.capacity;
//	this->fragments = new TElem[this->capacity];
//
//	for (int i = 0; i < this->numberOfFragments; i++)
//		this->fragments[i] = copyVector.fragments[i];
//}

//template <typename TElem>
//DynamicVector<TElem> & DynamicVecto<TElem>r::operator=(const DynamicVector<TElem> & assignVector)
//{
//	if (this == &assignVector)
//		return *this;
//
//	this->numberOfFragments = assignVector.numberOfFragments;
//	this->capacity = assignVector.capacity;
//	delete[] this->fragments;
//
//	for (int i = 0; i < this->numberOfFragments; i++)
//		this->fragments[i] = assignVector.fragments[i];
//
//	return *this;
//}

//template <typename TElem>
//TElem & DynamicVector<TElem>::operator[](int position)
//{
//	return this->fragments[position];
//}

//template <typename TElem>
//void DynamicVector<TElem>::addFootage(const TElem & newFootage)
//{
//	if (this->numberOfFragments >= this->capacity)
//		this->resize();
//
//	this->fragments[this->numberOfFragments] = newFootage;
//	this->numberOfFragments++;
//	//std::cout << this->numberOfFragments << "\n";
//}

//template <typename TElem>
//void DynamicVector<TElem>::updateFootage(const std::string & Title, const std::string & newLocation, const std::string & newDate, int & newAccessed, const std::string & newPreview)
//{
//	int position = DynamicVector<TElem>::findByTitle(Title);
//	this->fragments[position].setLocation(newLocation);
//	this->fragments[position].setTimeOfCreation(newDate);
//	this->fragments[position].setTimesAccessed(newAccessed);
//	this->fragments[position].setFootagePreview(newPreview);
//}


//template <typename TElem>
//int DynamicVector<TElem>::getNumberOfFragments() const
//{
//	return this->numberOfFragments;
//}

//template <typename TElem>
//TElem * DynamicVector<TElem>::getAllFragments() const
//{
//	return this->fragments;
//}

//template <typename TElem>
//DynamicVector<TElem>::~DynamicVector()
//{
//	delete[] this->fragments;
//}

//template <typename TElem>
//void DynamicVector<TElem>::resize(double factor)
//{
//	this->capacity *= static_cast<int>(factor);
//
//	TElem* auxiliarVector = new TElem[this->capacity];
//	for (int i = 0; i < this->numberOfFragments; i++)
//		auxiliarVector[i] = this->fragments[i];
//
//	delete[] this->fragments;
//	this->fragments = auxiliarVector;
//}

//template <typename TElem>
//int DynamicVector<TElem>::findByTitle(const std::string & Title)
//{
//	int position = -1;
//	for (int i = 0; i < this->numberOfFragments; i++)
//		if (this->fragments[i].getTitle() == Title)
//		{
//			position = i;
//			break;
//		}
//	return position;
//}

//template <typename TElem>
//void DynamicVector<TElem>::deleteFootage(int & position)
//{
//	//delete &this->fragments[position];
//	for (int i = position; i < this->numberOfFragments-1; i++)
//		this->fragments[i] = this->fragments[i + 1];
//	this->numberOfFragments--;
//	//delete &this->fragments[this->numberOfFragments];
//}
