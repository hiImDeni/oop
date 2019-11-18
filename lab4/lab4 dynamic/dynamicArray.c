#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
//#include "controller.h"
#include "Header.h"
#include <stdlib.h>
#include <string.h>

DynamicSignals * initialize(int capacity)
{
	DynamicSignals * signalData;
	signalData = (DynamicSignals*)malloc(sizeof(DynamicSignals));

	signalData->signals = (signal*)malloc(capacity * sizeof(signal));

	signalData->number_of_signals = 0;
	signalData->capacity = capacity;

	return signalData;
}

void resize(DynamicSignals* signalData)
{
	signalData->capacity *= 2;
	DynamicSignals* auxiliarVector = initialize(signalData->capacity);
	
	for (int i = 0; i < signalData->number_of_signals; i++)
		addSignal(auxiliarVector, signalData->signals[i]);//auxiliarVector->signals[i] = signalData->signals[i];
	if (signalData != NULL)
	{
		free(signalData->signals);
		signalData->signals = NULL;
	}
	signalData->signals = auxiliarVector->signals;
}

void addSignal(DynamicSignals * signalData, signal newSignal)
{
	if (signalData->number_of_signals >= signalData->capacity)
	{
		resize(signalData);
		//realloc(signalData, 2*signalData->capacity * sizeof(signal));
	}
	signalData->signals[signalData->number_of_signals++] = newSignal;
}

void deleteSignal(DynamicSignals * signalData, int position)
{
	for (int i = position; i < signalData->number_of_signals; i++)
	{
		signalData->signals[i].id = signalData->signals[i + 1].id;
		signalData->signals[i].priorityNumber = signalData->signals[i + 1].priorityNumber;
		strcpy(signalData->signals[i].modulatedSignal, signalData->signals[i + 1].modulatedSignal);
		strcpy(signalData->signals[i].type, signalData->signals[i + 1].type);
	}
	signalData->number_of_signals--;
	//free(signalData->signals[signalData->number_of_signals]);
}

void destroyArray(DynamicSignals* signalData)
{
	if (signalData != NULL)
	{
		free(signalData->signals);
		free(signalData->capacity);
		free(signalData->number_of_signals);
	}
	free(signalData);
}

void destroy_array(DynamicSignals* signalData)
{
	if (signalData != NULL)
	{
		free(signalData->signals);
		//free(signalData->capacity);
		//free(signalData->number_of_signals);
	}
	free(signalData);
}

void updateSignal(DynamicSignals* signalData, int id, char newModulatedSignal[], char newType[], int newPriorityNumber)
{
	int position = check_id(signalData, id);
	strcpy(signalData->signals[position].modulatedSignal, newModulatedSignal);
	strcpy(signalData->signals[position].type, newType);
	signalData->signals[position].priorityNumber = newPriorityNumber;
}
