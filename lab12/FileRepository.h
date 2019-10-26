#pragma once
#include "Repository.h"
#include <fstream>
#include <iostream>
//#include <mockpp>

class FileRepository: public Repository
{
	friend class ControllerA;
	friend class Tests;
	friend class UndoAction;
private:
	std::string dataFile;

	friend std::istream & operator>>(std::istream & is, TElem & footage);

	void readFromFile();

	void writeToFile();

public:
	FileRepository(std::string& File);

	//FileRepository(std::string& File, std::string& output);

	//void writeFootageToFile(TElem& footage);


	~FileRepository();

	bool add(const TElem & newFootage) override;
	TElem update(const std::string& Title, const std::string& newLocation, const std::string& newDate, int& newAccessed, const std::string& newPreview) override;
	TElem deleteRepository(const std::string & Title) override;

};


