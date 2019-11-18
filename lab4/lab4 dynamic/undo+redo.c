#include "Header.h"
#include "undo+redo.h"
#include "controller.h"
#include <stdlib.h>

DynamicSignals** createMatrix(DynamicSignals* SignalData, int number_of_operations)
{
	DynamicSignals** matrix = (DynamicSignals**)malloc(number_of_operations * sizeof(DynamicSignals*));
	for (int i = 0; i < number_of_operations; i++)
	{
		matrix[i] = (DynamicSignals*)malloc(SignalData->capacity * sizeof(signal));
		matrix[i]->number_of_signals = SignalData->number_of_signals;
		matrix[i]->capacity = SignalData->capacity;
	}
	return matrix;
}

void destroyMatrix(DynamicSignals** matrix, int number_of_operations)
{
	if (matrix != NULL)
	{
		for (int i = 0; i < number_of_operations; i++)
			if (matrix[i] != NULL)
			{
				destroyArray(matrix[i]);
			}
		free(matrix);
	}
}

DynamicSignals** resizeMatrix(DynamicSignals** matrix, int maximum_number_of_operations)
{
	DynamicSignals** auxiliaryMatrix = (DynamicSignals**)malloc(2 * maximum_number_of_operations * sizeof(DynamicSignals*));
	for (int i = 0; i < maximum_number_of_operations; i++)
	{
		auxiliaryMatrix[i] = (DynamicSignals*)malloc(matrix[i]->capacity * sizeof(DynamicSignals));
		auxiliaryMatrix[i]->number_of_signals = matrix[i]->number_of_signals;
		auxiliaryMatrix[i]->capacity = matrix[i]->capacity;
	}
	return auxiliaryMatrix;
}

/*void addOperation(DynamicSignals** matrix, DynamicSignals* operation, int current_number_of_operations, int maximum_number_of_operations)
{  
	/*if (current_number_of_operations >= maximum_number_of_operations)
		matrix = resizeMatrix(matrix, 2 * maximum_number_of_operations);
	if (matrix[current_number_of_operations]->number_of_signals >= matrix[current_number_of_operations]->capacity)
		resize(matrix[current_number_of_operations]);
	for (int i = 0; i < operation->number_of_signals; i++)
	{
		matrix[current_number_of_operations]->signals[i].id = operation->signals[i].id;
		strcpy(matrix[current_number_of_operations]->signals[i].modulatedSignal, operation->signals[i].modulatedSignal);
		strcpy(matrix[current_number_of_operations]->signals[i].type, operation->signals[i].type);
		matrix[current_number_of_operations]->signals[i].priorityNumber = operation->signals[i].priorityNumber;
	}
	matrix[current_number_of_operations]->capacity = operation->capacity;
	matrix[current_number_of_operations]->number_of_signals = operation->number_of_signals;
}*/

void resizeOperation(lastPerformedOperation* operations)
{
	operations->capacity *= 2;
	lastPerformedOperation* auxiliarVector = createList(operations->capacity);
	for (int i = 0; i < operations->number_of_operations; i++)
		auxiliarVector->current_operation[i] = operations->current_operation[i];

	if (operations != NULL)
	{
		free(operations->current_operation);
		operations->current_operation = NULL;
	}
	operations->current_operation = auxiliarVector->current_operation;
}

void addOperationName(lastPerformedOperation* operations, char current)
{
	if (operations->number_of_operations >= operations->capacity)
		resizeOperation(operations);
	operations->current_operation[operations->number_of_operations++] = current;
}

void addOperation(DynamicSignals* undoRedoList, lastPerformedOperation* operations, signal undoableSignal, char current)
{
	addSignal(undoRedoList, undoableSignal);
	addOperationName(operations, current);
	for (int i =0; i < undoRedoList->number_of_signals; i++)
		printf("%d, %s, %s, %d\n", undoRedoList->signals[i].id, undoRedoList->signals[i].modulatedSignal, undoRedoList->signals[i].type, undoRedoList->signals[i].priorityNumber);
	for (int i = 0; i < operations->number_of_operations; i++)
		printf("%c", operations->current_operation[i]);
}

void popOperation(DynamicSignals* undoRedoList, DynamicSignals* signalData, lastPerformedOperation* operations)
{
	operations->number_of_operations--;
	printf("%d, %s, %s, %d\n", undoRedoList->signals[undoRedoList->number_of_signals - 1].id, undoRedoList->signals[undoRedoList->number_of_signals - 1].modulatedSignal, undoRedoList->signals[undoRedoList->number_of_signals - 1].type, undoRedoList->signals[undoRedoList->number_of_signals - 1].priorityNumber);
	if (operations->current_operation[operations->number_of_operations] == 'd')
	{
		//printf("%d, %s, %s, %d\n", undoRedoList->signals[undoRedoList->number_of_signals - 1].id, undoRedoList->signals[undoRedoList->number_of_signals - 1].modulatedSignal, undoRedoList->signals[undoRedoList->number_of_signals - 1].type, undoRedoList->signals[undoRedoList->number_of_signals - 1].priorityNumber);
		addSignal(signalData, undoRedoList->signals[undoRedoList->number_of_signals-1]);
		undoRedoList->number_of_signals--;
	}
	if (operations->current_operation[operations->number_of_operations] == 'a')
	{
		//printf("%d, %s, %s, %d\n", undoRedoList->signals[undoRedoList->number_of_signals - 1].id, undoRedoList->signals[undoRedoList->number_of_signals - 1].modulatedSignal, undoRedoList->signals[undoRedoList->number_of_signals - 1].type, undoRedoList->signals[undoRedoList->number_of_signals - 1].priorityNumber);
		int position = check_id(signalData, undoRedoList->signals[undoRedoList->number_of_signals - 1].id);
		deleteSignal(signalData, position);
		undoRedoList->number_of_signals--;
	}
	if (operations->current_operation[operations->number_of_operations] == 'u')
	{
		//printf("%d, %s, %s, %d\n", undoRedoList->signals[undoRedoList->number_of_signals - 1].id, undoRedoList->signals[undoRedoList->number_of_signals - 1].modulatedSignal, undoRedoList->signals[undoRedoList->number_of_signals - 1].type, undoRedoList->signals[undoRedoList->number_of_signals - 1].priorityNumber);
		updateSignal(signalData, undoRedoList->signals[undoRedoList->number_of_signals-1].id, undoRedoList->signals[undoRedoList->number_of_signals - 1].modulatedSignal, 
			undoRedoList->signals[undoRedoList->number_of_signals - 1].type, 
			undoRedoList->signals[undoRedoList->number_of_signals - 1].priorityNumber);
		undoRedoList->number_of_signals--;
	}
}

lastPerformedOperation* createList(int capacity)
{
	lastPerformedOperation* operationData = (lastPerformedOperation*)malloc(sizeof(lastPerformedOperation));
	operationData->current_operation = (char*)malloc(capacity * sizeof(char));
	operationData->capacity = capacity;
	operationData->number_of_operations = 0;

	return operationData;
}

void destroyOperation(lastPerformedOperation* operations)
{
	if (operations == NULL)
		return;
	free(operations->current_operation);
	free(operations->capacity);
	free(operations->number_of_operations);
	free(operations);
}


