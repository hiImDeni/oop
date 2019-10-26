#pragma once
#include "Repository.h"
#include "FileRepository.h"
//#include "CSVRepository.h"
//#include "HTMLRepository.h"
#include <vector>
#include <algorithm>
#include "UndoAction.h"

using namespace std;


class ControllerA
{
	friend class lab12final;
	friend class Tests;
private:
	Repository* repository;
	vector<UndoAction*> undos;
	vector<UndoAction*> redos;
	//FileRepository repository;
	//fstream file;
public:
	ControllerA(Repository* repo) : repository{ repo } { }

	//Repository* getRepository() const { return repository; }


	vector<TElem>& getControllerElements() { return this->repository->getElements(); }
	vector<TElem>& filter(std::string & location, int & timesAccessed);
	//void saveList(std::string& file);

	Repository* getRepo() const { return repository; }

	void executeUndo();

	void executeRedo();

	~ControllerA();

private:
	bool addController(const std::string& Title, const std::string& Location, const std::string& Date, int& Accessed, const std::string& Preview);
	bool updateController(const std::string & Title, const std::string & newLocation, const std::string & newDate, int & newAccessed, const std::string & newPreview);
	bool deleteController(const std::string & Title);

	//static void testController();


	
};



