#pragma once
#include "Footage.h"
#include "Validator.h"
#include <vector>
#include <fstream>
#include <iostream>

class UndoAction;
using namespace std;

class Repository
{
	friend class ControllerA;
	friend class Tests;
protected:
	vector<TElem> elements;
	//vector<UndoAction*> undos;
	//std::string outputFile;
	//fstream file;
	//std::string dataFile;
public:
	Repository();

	//Repository(std::string& file) { this->outputFile = file; this->storeData(); }
	
	vector<TElem>& getElements() { return elements;  }

	virtual int findByTitle(const std::string & Title);

	virtual ~Repository();

	virtual bool add(const TElem & newFootage);
	virtual TElem update(const std::string& Title, const std::string& newLocation, const std::string& newDate, int& newAccessed, const std::string& newPreview);
	virtual TElem deleteRepository(const std::string & Title);

	//void initialization();

	//virtual void saveCSV(std::string & file);
	//virtual void saveHTML(std::string & file);

	//void storeData();
};

