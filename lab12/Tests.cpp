#include "Tests.h"
#include "FakeRepository.h"
#include <assert.h>


Tests::Tests()
{
}

void Tests::runTests()
{
	this->testFootage();
	this->testRepository();
	//this->testFileRepositoy();
	//this->testController();
	this->testValidator();

	this->testIsolatedController();
}


void Tests::testRepository()
{
	Repository testRepository{};
	try
	{
		std::string title = "title12";
		std::string location = "location";
		std::string timeOfCreation = "10-05-2543";
		std::string footagePreview = "preview";
		int timesAccessed = 6;
		TElem newFootage = TElem(title, location, timeOfCreation, timesAccessed, footagePreview);
		testRepository.add(newFootage);
		assert(testRepository.findByTitle(title) != -1);

		//assert(testRepository.getElements().size() == 1);
		std::string title2 = "title23";
		assert(testRepository.findByTitle(title2) == -1);
		location = "location2";
		timeOfCreation = "05-12-2043";
		footagePreview = "preview2";
		timesAccessed = 3;
		newFootage = TElem(title2, location, timeOfCreation, timesAccessed, footagePreview);
		testRepository.add(newFootage);
		testRepository.deleteRepository(title2);
		//assert(testRepository.getElements().size() == 1);

		location = "loc";
		timeOfCreation = "053";
		footagePreview = "preview";
		testRepository.update(title, location, timeOfCreation, timesAccessed, footagePreview);
		/*assert(testRepository.getElements()[0].getTitle() == "title12");
		assert(testRepository.getElements()[0].getLocation() == "loc");
		assert(testRepository.getElements()[0].getTimeOfCreation() == "053");
		assert(testRepository.getElements()[0].getFootagePreview() == "preview");
		assert(testRepository.getElements()[0].getTimesAccessed() == 3);*/
	}
	catch (nameError&)
	{
		assert(true);
	}
	catch (signalError&)
	{
		assert(true);
	}
	catch (exception&)
	{
		assert(true);
	}
}

void Tests::testController()
{
	std::string file = "test.txt";
	Repository* testRepository = new FileRepository{ file };

	ControllerA testController{ testRepository };
	
	std::string title = "title3";
	std::string location = "location";
	std::string timeOfCreation = "10-05-2543";
	std::string footagePreview = "preview";
	int timesAccessed = 6;

	testController.addController(title, location, timeOfCreation, timesAccessed, footagePreview);
	//assert(testController.getControllerElements().size() == 1);

	std::string title2 = "t";
	location = "l";
	timeOfCreation = "t";
	footagePreview = "p";
	
	assert(testController.addController(title2, location, timeOfCreation, timesAccessed, footagePreview));
	assert(testController.deleteController(title2));
	

	try
	{
		std::string file1 = "inexistent file";
		FileRepository newRepo{ file1 };}
	catch (exception&) {
		assert(true);}
}

void Tests::testFileRepositoy()
{
	std::string testFile = "test.txt";
	FileRepository testFileRepo{ testFile };
	testFileRepo.readFromFile();
	assert(testFileRepo.getElements().size() == 0);

	/*std::string title = "test";
	std::string location = "loc";
	std::string date = "10-03-1256";
	int accessed = 3;
	std::string prev = "prev";

	testFileRepo.update(title, location, date, accessed, prev);*/
	
	testFile = "someFile";
	try
	{
		FileRepository newRepo{ testFile };
	}
	
	catch (exception&)
	{
		assert(true);}
}

void Tests::testValidator()
{
	std::string title = "";
	std::string location = "loc";
	std::string timeOfCreation = "time";
	std::string footagePreview = "prev";
	int timesAccessed = 3;
	TElem newFootage = TElem(title, location, timeOfCreation, timesAccessed, footagePreview);
	try
	{
		Validator::validateFootage(newFootage);}
	catch (signalError& er)
	{
		//assert(true);
		assert(er.getMessage() == "Invalid data");}

	title = "title6";
	location = "";
	timeOfCreation = "time";
	footagePreview = "prev";
	timesAccessed = 3;
	newFootage = TElem(title, location, timeOfCreation, timesAccessed, footagePreview);
	try
	{
		Validator::validateFootage(newFootage);}
	catch (signalError&)
	{
		assert(true);}

	title = "title7";
	location = "loc";
	timeOfCreation = "";
	footagePreview = "prev";
	timesAccessed = 3;
	newFootage = TElem(title, location, timeOfCreation, timesAccessed, footagePreview);
	//try
	//{
		Validator::validateFootage(newFootage);//}
	//catch (signalError&) {assert(true);}

	title = "title8";
	location = "loc";
	timeOfCreation = "time";
	footagePreview = "";
	timesAccessed = 3;
	newFootage = TElem(title, location, timeOfCreation, timesAccessed, footagePreview);
	try
	{
		Validator::validateFootage(newFootage);}
	catch (signalError&)
	{
		assert(true);}

	title = "title9";
	location = "loc";
	timeOfCreation = "time";
	footagePreview = "prev";
	int timesAccessd = -3;
	newFootage = TElem(title, location, timeOfCreation, timesAccessd, footagePreview);
	try
	{
		Validator::validateFootage(newFootage);}
	catch (signalError&)
	{
		assert(true);}
}


void Tests::testIsolatedController()
{
	Repository* repo = new FakeRepository{};
	ControllerA testController{ repo };

	std::string title = "title7";
	std::string location = "loc";
	std::string timeOfCreation = "time";
	std::string footagePreview = "prev";
	int timesAccessed = 6;

	TElem footage = TElem(title, location, timeOfCreation, timesAccessed, footagePreview);

	assert(testController.addController(title, location, timeOfCreation, timesAccessed, footagePreview));

	timesAccessed = 10;
	assert(testController.updateController(title, "", "", timesAccessed, ""));
	assert(testController.deleteController(title));
	assert(testController.getRepo()->findByTitle(title) != -1);
}


Tests::~Tests()
{
}


void Tests::testFootage()
{
	std::string title = "title2";
	std::string location = "location2";
	std::string timeOfCreation = "05-12-2043";
	std::string footagePreview = "preview2";
	int timesAccessed = 3;
	TElem newFootage = TElem(title, location, timeOfCreation, timesAccessed, footagePreview);
	assert(newFootage.getTitle() == "title2");
	assert(newFootage.getLocation() == "location2");
	assert(newFootage.getTimeOfCreation() == "05-12-2043");
	assert(newFootage.getFootagePreview() == "preview2");
	assert(newFootage.getTimesAccessed() == 3);
}