#pragma once
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector elements;
public:
	Repository() {}
	void add(const TElem& newFootage);
	void update(const std::string& Title, const std::string& newLocation, const std::string& newDate, int& newAccessed, const std::string& newPreview);
	void deleteRepository(int& position);
	
	//DynamicVector operator[]
	//Repository& operator[](int position);
	
	DynamicVector getElements() const { return elements;  }

	~Repository();
};

