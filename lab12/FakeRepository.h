#pragma once
#include "Repository.h"


class FakeRepository : public Repository
{
	friend class ControllerA;
	friend class Tests;
public:
	vector<TElem> fakeList;
public:
	FakeRepository();
	~FakeRepository();

	FakeRepository getFakeRepository(Repository fileRepo) { return (*this); }
	bool add(const TElem& newFootage) override;
	TElem deleteRepository(const std::string & Title) override;
	TElem update(const std::string& Title, const std::string& newLocation, const std::string& newDate, int& newAccessed, const std::string& newPreview) override;
	int findByTitle(const std::string & Title) override;
};

