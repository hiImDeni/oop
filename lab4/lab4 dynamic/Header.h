#pragma once
#include "undo+redo.h"

void run_tests();

int run_menu();

typedef struct
{
	int id;
	char modulatedSignal[25];
	char type[20];
	int priorityNumber;
}signal;

typedef struct
{
	signal *signals;
	int number_of_signals, capacity;
}DynamicSignals;

void resize(DynamicSignals* signalData);

int check_id(DynamicSignals * signalData, int id);

DynamicSignals * initialize(int);

void addSignal(DynamicSignals*, signal);

void deleteSignal(DynamicSignals*, int);

void destroyArray(DynamicSignals*);

void destroy_array(DynamicSignals* signalData);

void updateSignal(DynamicSignals* signalData, int id, char newModulatedSignal[], char newType[], int newPriorityNumber);

void undo(DynamicSignals * signalData, DynamicSignals* undoSignals, lastPerformedOperation* operations);

void redo(DynamicSignals * signalData, DynamicSignals* redoSignals, lastPerformedOperation* operations);

int check_id(DynamicSignals * signalData, int id);

