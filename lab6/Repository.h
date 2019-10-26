#pragma once
#include "DynamicVector.h"

typedef Footage TElem;

class Repository
{
	friend class ControllerA;
	friend class Tests;
private:
	DynamicVector<TElem> elements;
public:
	Repository() {}
	/*void add(const TElem & newFootage);
	void update(const std::string& Title, const std::string& newLocation, const std::string& newDate, int& newAccessed, const std::string& newPreview);
	void deleteRepository(int& position);*/
	
	//DynamicVector operator[]
	//Repository& operator[](int position);
	
	DynamicVector<Footage> getElements() const { return elements;  }

	void initialization();

	~Repository();
private:
	void add(const TElem & newFootage);
	void update(const std::string& Title, const std::string& newLocation, const std::string& newDate, int& newAccessed, const std::string& newPreview);
	void deleteRepository(int& position);
};

