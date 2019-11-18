#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include "undo+redo.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

signal create_signal(int id, char modulatedSignal[], char type[], int priorityNumber)
{
	signal newSignal;
	newSignal.id = id;
	strcpy(newSignal.modulatedSignal, modulatedSignal);
	strcpy(newSignal.type, type);
	newSignal.priorityNumber = priorityNumber;
	return newSignal;
}

void test_dynamicArray()
{
	DynamicSignals* list = initialize(3);
	if (list == NULL)
		assert(0);
	assert(list->capacity == 3);
	assert(list->number_of_signals == 0);

	signal newSignal = create_signal(1, "signal", "damage-inner", 4);
	addSignal(list, newSignal);
	signal anotherSignal = create_signal(2, "signal1", "damage-outer", 7);
	addSignal(list, anotherSignal);
	assert(list->number_of_signals == 2);
	deleteSignal(list, 1);
	assert(list->number_of_signals == 1);

	destroy_array(list);
}

/*void test_undo()
{
	DynamicSignals* list = initialize(10);
	DynamicSignals* undoSignals = initialize(10);
	lastPerformedOperation* operations = createList(10);

	signal newSignal = create_signal(1, "signal", "damage-inner", 4);
	addSignal(list, newSignal);
	signal anotherSignal = create_signal(2, "signal1", "damage-outer", 7);
	addSignal(list, anotherSignal);
	
	undo(list, undoSignals, operations);
	assert(list->number_of_signals == 1);
	destroyArray(undoSignals);
	destroyOperation(operations);
}*/

void run_tests()
{
	test_dynamicArray();
	//test_undo();
}