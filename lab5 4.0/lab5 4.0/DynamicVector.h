#pragma once
#include "Footage.h"

typedef Footage TElem;

class DynamicVector
{
private:
	TElem * fragments;
	int capacity, numberOfFragments;
public:
	DynamicVector(int cap = 100);
	DynamicVector(const DynamicVector& copyVector);
	DynamicVector& operator=(const DynamicVector& assignVector);
	TElem& operator[](int position);

	void addFootage(const TElem& newFootage);
	void updateFootage(const std::string& Title, const std::string& newLocation, const std::string& newDate, int& newAccessed, const std::string& newPreview);
	int findByTitle(const std::string& Title);
	void deleteFootage(int& position);
	
	int getNumberOfFragments() const;
	TElem* getAllFragments() const;
	~DynamicVector();
private:
	void resize(double factor = 2);
};

