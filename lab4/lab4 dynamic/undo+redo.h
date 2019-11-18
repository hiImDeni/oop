#pragma once
#include "Header.h"

typedef struct
{
	char *current_operation;
	int capacity;
	int number_of_operations;
}lastPerformedOperation;

//void addOperation(DynamicSignals*, lastPerformedOperation*, signal, char);

void addOperation (DynamicSignals*, lastPerformedOperation*, signal, char);

void copy_in_original_list(DynamicSignals* originalList, DynamicSignals* newList);

void popOperation(DynamicSignals* undoRedoList, DynamicSignals* signalData, lastPerformedOperation* operations);

lastPerformedOperation* createList(int);

void destroyOperation(lastPerformedOperation*);

