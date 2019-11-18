#include "Header.h"
#include <stdlib.h>

DynamicSignals * initialize(int capacity)
{
	DynamicSignals *signalData = (DynamicSignals*)malloc(sizeof(DynamicSignals));

	signalData->signals = (signal*)malloc(capacity * sizeof(signal));

	signalData->number_of_signals = 0;
	signalData->capacity = capacity;

	return signalData;
}

void resize(DynamicSignals* signalData)
{
	signalData->capacity *= 2;
	TElem* arr2 = (TElem*)malloc(dynamicVector->capacity * sizeof(TElem));
	for (int i = 0; i < signalData->size; i++)
		arr2[i] = signalData->arr[i];
	free(signalData->arr);
	signalData->arr = arr2;
}

void addSignal(DynamicSignals * signalData, signal newSignal)
{
	if (signalData->number_of_signals >= signalData->capacity)
	{
		resize(signalData);
	}
	signalData->signals[signalData->number_of_signals++] = newSignal;
}

void destroyArray(DynamicSignals* signalData)
{
	if (signalData != NULL)
		free(signalData->signals);
	
	free(signalData);
}

