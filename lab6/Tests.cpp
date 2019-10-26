#include "Tests.h"
#include <assert.h>


Tests::Tests()
{
}

void Tests::runTests()
{
	this->testDynamicVector();
	this->testRepository();
	this->testController();
}

void Tests::testDynamicVector()
{
	DynamicVector<TElem> testVector(10);
	Tests::testAddDynamicVector(testVector);
	Tests::testDeleteDynamicVector(testVector);
}

void Tests::testRepository()
{
	Repository testRepository{};
	Tests::testAddRepository(testRepository);
	Tests::testDeleteRepository(testRepository);
}

void Tests::testController()
{
	Repository testRepository{};
	ControllerA testController{ testRepository };
	Tests::testAddController(testController);
}


Tests::~Tests()
{
}

void Tests::testAddDynamicVector(DynamicVector<TElem> & testVector)
{
	std::string title = "title";
	std::string location = "location";
	std::string timeOfCreation = "10-05-2543";
	std::string footagePreview = "preview";
	int timesAccessed = 6;
	TElem newFootage = TElem(title, location, timeOfCreation, timesAccessed, footagePreview);
	testVector.addFootage(newFootage);
	assert(testVector.getNumberOfFragments() == 1);
	assert(testVector.getAllFragments()[0].getTitle() == "title");
}

void Tests::testDeleteDynamicVector(DynamicVector<TElem> & testVector)
{
	std::string title = "";
	std::string location = "";
	std::string timeOfCreation = "";
	std::string footagePreview = "";
	int timesAccessed = 3;
	TElem newFootage = TElem(title, location, timeOfCreation, timesAccessed, footagePreview);
	testVector.addFootage(newFootage);
	int position = 1;
	testVector.deleteFootage(position);
	assert(testVector.getNumberOfFragments() == 1);
}

void Tests::testAddRepository(Repository & testRepository)
{
	std::string title = "title";
	std::string location = "location";
	std::string timeOfCreation = "10-05-2543";
	std::string footagePreview = "preview";
	int timesAccessed = 6;
	TElem newFootage = TElem(title, location, timeOfCreation, timesAccessed, footagePreview);
	testRepository.add(newFootage);
	assert(testRepository.getElements().getNumberOfFragments() == 1);
	assert(testRepository.getElements()[0].getFootagePreview() == "preview");
}

void Tests::testDeleteRepository(Repository & testRepository)
{
	std::string title = "title2";
	std::string location = "location2";
	std::string timeOfCreation = "05-12-2043";
	std::string footagePreview = "preview2";
	int timesAccessed = 3;
	TElem newFootage = TElem(title, location, timeOfCreation, timesAccessed, footagePreview);
	testRepository.add(newFootage);
	int position = 1;
	testRepository.deleteRepository(position);
	assert(testRepository.getElements().getNumberOfFragments() == 1);
}

void Tests::testAddController(ControllerA & testController)
{
	std::string title = "title";
	std::string location = "location";
	std::string timeOfCreation = "10-05-2543";
	std::string footagePreview = "preview";
	int timesAccessed = 6;

	testController.addController(title, location, timeOfCreation, timesAccessed, footagePreview);
	assert(testController.getRepository().getElements().getNumberOfFragments() == 1);
}

void Tests::testDeleteController(ControllerA & testController)
{
	std::string title = "";
	std::string location = "";
	std::string timeOfCreation = "";
	std::string footagePreview = "";
	int timesAccessed = 3;
	int position = 1;

	testController.addController(title, location, timeOfCreation, timesAccessed, footagePreview);
	testController.deleteController(position);
	assert(testController.getRepository().getElements().getNumberOfFragments() == 1);
}
