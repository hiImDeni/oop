#pragma once
#include "DynamicVector.h"
#include "ControllerA.h"
#include "Footage.h"
#include "Repository.h"

class Tests
{
public:
	Tests();
	void runTests();
	~Tests();
private:
	void testDynamicVector();
	void testRepository();
	void testController();

	void static testAddDynamicVector(DynamicVector& testVector);
	void static testDeleteDynamicVector(DynamicVector& testVector);

	void static testAddRepository(Repository& testRepository);
	void static testDeleteRepository(Repository& testRepository);

	void static testAddController(ControllerA& testController);
	void static testDeleteController(ControllerA& testController);
};

