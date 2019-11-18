#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include "undo+redo.h"
#include <crtdbg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "controller.h"

void print_menu()
{
	printf("\nCommand formats: \n");
	printf("   -> add <id>, <modulatedSignal>, <type>, <priorityNumber>\n");
	printf("   -> update <id>, <newModulatedSignal>, <newType>, <newPriorityNumber>\n");
	printf("   -> delete <id>\n");
	printf("   -> list\n");
	printf("   -> list <type>\n");
	printf("   -> list <maximumPriorityNumber\n");
	printf("   -> undo\n");
	printf("   -> redo\n");
	printf("   -> exit\n\n");
}

int split_commands(char parameters[6][25], char command[])
{
	char *command_pointer;
	command_pointer = strtok(command, ", ");
	int counter = 0;
	while (command_pointer)
	{
		strcpy(parameters[counter], command_pointer);
		counter++;
		command_pointer = strtok(NULL, ", ");
	}
	return counter;
}

int check_id(DynamicSignals * signalData, int id)
{
	for (int i = 0; i < signalData->number_of_signals; i++)
		if (signalData->signals[i].id == id)
			return i;
	return -1;
}

void add(DynamicSignals * signalData, DynamicSignals* undoRedo, lastPerformedOperation* operations, int id, char modulatedSignal[25], char type[20], int priorityNumber)
{
	signal newSignal;
	newSignal.id = id;
	strcpy(newSignal.modulatedSignal, modulatedSignal);
	strcpy(newSignal.type, type);
	newSignal.priorityNumber = priorityNumber;
	if (check_id(signalData, id) != -1)
		printf("id already exists\n");
	else
	{
		addSignal(signalData, newSignal);
		addOperation(undoRedo, operations, newSignal, 'a');
	}
}

void update(DynamicSignals * signalData, DynamicSignals* undoRedo, lastPerformedOperation* operations, int id, char newModulatedSignal[25], char newType[20], int newPriorityNumber)
{
	int position = check_id(signalData, id);
	if (position == -1)
		printf("id does not exist\n");
	else
	{
		addOperation(undoRedo, operations, signalData->signals[position], 'u');
		strcpy(signalData->signals[position].modulatedSignal, newModulatedSignal);
		strcpy(signalData->signals[position].type, newType);
		signalData->signals[position].priorityNumber = newPriorityNumber;
	}
}

void delete_signal(DynamicSignals* signalData, DynamicSignals* undoRedo, lastPerformedOperation* operations, int id)
{
	int position = check_id(signalData, id);
	if (position == -1)
		printf("id does not exist\n");
	else
	{
		addOperation(undoRedo, operations, signalData->signals[position], 'd');
		deleteSignal(signalData, position);
	}
}

void list(DynamicSignals * signalData)
{
	for (int i = 0; i < signalData->number_of_signals; i++)
		printf("id: %d, modulatedSignal: %s, type: %s, priorityNumber: %d\n", signalData->signals[i].id, 
			signalData->signals[i].modulatedSignal, signalData->signals[i].type, signalData->signals[i].priorityNumber);
}

void list_type(DynamicSignals * signalData, char type[])
{
	for (int i = 0; i < signalData->number_of_signals; i++)
		if(strcmp(signalData->signals[i].type, type) == 0)
			printf("id: %d, modulatedSignal: %s, type: %s, priorityNumber: %d\n", signalData->signals[i].id,
			signalData->signals[i].modulatedSignal, signalData->signals[i].type, signalData->signals[i].priorityNumber);
}

void sort_by_modulated_signal(DynamicSignals* signalData)
{
	for(int i = 0; i < signalData->number_of_signals-1; i++)
		for (int j = i+1; j < signalData->number_of_signals; j++)
		{
			if (strcmp(signalData->signals[i].modulatedSignal, signalData->signals[j].modulatedSignal) > 0)
			{
				signal auxiliarSignal = signalData->signals[i];
				signalData->signals[i] = signalData->signals[j];
				signalData->signals[j] = auxiliarSignal;
			}		
		}
}

void list_priority_number(DynamicSignals * signalData, int maximumPriorityNumber)
{
	DynamicSignals* smallerPriorityNumber = initialize(100);
	for (int i = 0; i < signalData->number_of_signals; i++)
		if (signalData->signals[i].priorityNumber < maximumPriorityNumber)
			addSignal(smallerPriorityNumber, signalData->signals[i]);
	sort_by_modulated_signal(smallerPriorityNumber);
	for(int i = 0; i < smallerPriorityNumber->number_of_signals; i++)
			printf("id: %d, modulatedSignal: %s, type: %s, priorityNumber: %d\n", smallerPriorityNumber->signals[i].id,
				smallerPriorityNumber->signals[i].modulatedSignal, smallerPriorityNumber->signals[i].type, smallerPriorityNumber->signals[i].priorityNumber);
}

void copy_in_original_list(DynamicSignals* originalList, DynamicSignals* newList)
{
	if (originalList != NULL)
	{
		free(originalList->signals);
		originalList->signals = NULL;
		free(originalList->capacity);
		free(originalList->number_of_signals);
	}
	for (int i = 0; i < newList->number_of_signals; i++)
	{
		originalList->signals[i].id = newList->signals[i].id;
		originalList->signals[i].priorityNumber = newList->signals[i].priorityNumber;
		strcpy(originalList->signals[i].modulatedSignal, newList->signals[i].modulatedSignal);
		strcpy(originalList->signals[i].type, newList->signals[i].type);
	}
	originalList->number_of_signals = newList->number_of_signals;
	originalList->capacity = newList->capacity;
}

void undo(DynamicSignals * signalData, DynamicSignals* undoSignals, lastPerformedOperation* operations)
{
	//popOperation(undoList, signalData, currentNumberOfOperations);
	popOperation(undoSignals, signalData, operations);
}

void redo(DynamicSignals * signalData, DynamicSignals* redoSignals, lastPerformedOperation* operations)
{
	popOperation(redoSignals, signalData, operations);
}

int run_menu()
{
	DynamicSignals *signalData = initialize(100);
	//DynamicSignals **undoList = createMatrix(signalData, 100);
	//DynamicSignals **redoList = createMatrix(signalData, 100);
	DynamicSignals* undoSignals = initialize(100);
	DynamicSignals* redoSignals = initialize(100);
	lastPerformedOperation* undoOperations = createList(100);
	lastPerformedOperation* redoOperations = createList(100);
	//int maximumNumberOfOperationsUndo = 100;
	//int maximumNumberOfOperationsRedo = 100;
	int numberOfOperationsUndo = 0;
	int numberOfOperationsRedo = 0;
	while (1)
	{
		char command[100];
		char parameters[6][25];

		print_menu();
		scanf("%[^\n]%*c", command);
		if (strcmp(command, "exit") == 0)
			return 0;
		else
		{
			int counter = split_commands(parameters, command);
			if (strcmp(parameters[0], "add") == 0)
			{
				if (counter == 5)
				{
					//addOperation(undoList, signalData, numberOfOperationsUndo, maximumNumberOfOperationsUndo);
					add(signalData, undoSignals, undoOperations, atoi(parameters[1]), parameters[2], parameters[3], atoi(parameters[4]));
					//numberOfOperationsUndo++;
				}
				else
					printf("Invalid command\n");
			}
			else
			{
				if (strcmp(parameters[0], "update") == 0)
				{
					if (counter == 5)
					{
						//addOperation(undoList, signalData, numberOfOperationsUndo, maximumNumberOfOperationsUndo);
						update(signalData, undoSignals, undoOperations, atoi(parameters[1]), parameters[2], parameters[3], atoi(parameters[4]));
						//numberOfOperationsUndo++;
					}
					else
						printf("Invalid command\n");
				}
				else
				{
					if (strcmp(parameters[0], "delete") == 0)
					{
						if (counter == 2)
						{
							//addOperation(undoList, signalData, numberOfOperationsUndo, maximumNumberOfOperationsUndo);
							delete_signal(signalData, undoSignals, undoOperations, atoi(parameters[1]));
							//numberOfOperationsUndo++;
						}
						else
							printf("Invalid command\n");
					}
					else
					{
						if (strcmp(parameters[0], "list") == 0)
						{
							if (counter == 1)
								list(signalData);
							else
							{
								if (counter == 2)
								{
									if (atoi(parameters[1]))
										list_priority_number(signalData, atoi(parameters[1]));
									else
										list_type(signalData, parameters[1]);
								}
								//else
									//printf("invalid command\n");
							}
						}
						else
						{
							//printf("%s", parameters[0]);
							if (strcmp(parameters[0], "undo") == 0)
							{
								//addOperation(redoList, undoList[numberOfOperationsUndo], numberOfOperationsRedo, maximumNumberOfOperationsRedo);
								//numberOfOperationsRedo++;
								//undo(undoList, signalData, numberOfOperationsUndo);
								//numberOfOperationsUndo--;
								//printf("now?");
								if (undoOperations->number_of_operations == 0)
									printf("nothing to undo\n");
								else
								{
									char lastOperation;
									if (undoOperations->current_operation[undoOperations->number_of_operations - 1] == 'a')
										lastOperation = 'd';
									if (undoOperations->current_operation[undoOperations->number_of_operations - 1] == 'd')
										lastOperation = 'a';
									if (undoOperations->current_operation[undoOperations->number_of_operations - 1] == 'u')
										lastOperation = 'u';
									addOperation(redoSignals, redoOperations, undoSignals->signals[undoSignals->number_of_signals - 1],
										lastOperation);
									undo(signalData, undoSignals, undoOperations);
								}
							}
							else
							{
								if (strcmp(parameters[0], "redo") == 0 && counter == 1)
								{
									//redo(redoList, signalData, numberOfOperationsRedo);
									//numberOfOperationsRedo--;
									if (redoOperations->number_of_operations == 0)
										printf("nothing to redo\n");
									else
										undo(signalData, redoSignals, redoOperations);
								}
								else
									printf("invalid command\n");
							}
						}
					}
				}
			}
		}
	}
	destroyArray(signalData);
	destroyArray(undoSignals);
	destroyArray(redoSignals);
	destroyOperation(undoOperations);
	destroyOperation(redoOperations);
	//destroyArray(undoList);
	//destroyArray(redoList);
	_CrtDumpMemoryLeaks();
}