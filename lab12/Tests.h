#pragma once
#include "ControllerA.h"
#include "Footage.h"
#include "Repository.h"
//#include "FakeRepository.h"


class Tests
{
public:
	Tests();
	void runTests();
	~Tests();
private:
	void testFootage();
	void testRepository();
	void testController();
	void testFileRepositoy();
	void testValidator();
	void testIsolatedController();

	//void static testAddController(ControllerA& testController);
	//void static testDeleteController(ControllerA& testController);
};

