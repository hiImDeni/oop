// main.cpp : Defines the entry point for the console application.
//

//#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*struct signal
{
	int id;
	char modulatedSignal[25];
	char type[20];
	int priorityNumber;
}data[101];*/

int add(signal signals[101], int number_of_signals, int id, char modulatedSignal[25], char type[20], int priorityNumber)
{
	int ok = 1;
	for(int i = 0; i < number_of_signals; i++)
		if (signals[i].id == id)
		{
			ok = 0;
			printf("id already exists");
			break;
		}
	if (ok == 1)
	{
		signals[number_of_signals].id = id;
		strcpy(signals[number_of_signals].modulatedSignal, modulatedSignal);
		strcpy(signals[number_of_signals].type, type);
		signals[number_of_signals].priorityNumber = priorityNumber;
		number_of_signals++;
	}
	return number_of_signals;
}

void update(signal signals[], int number_of_signals, int id, char newModulatedSignal[], char newType[], int newPriorityNumber)
{
	int ok;
	ok = 0;
	int i = 0;
	for (i = 0; i < number_of_signals; i++)
		if (signals[i].id == id)
		{
			strcpy(signals[i].modulatedSignal, newModulatedSignal);
			strcpy(signals[i].type, newType);
			signals[i].priorityNumber = newPriorityNumber;
			ok = 1;
			break;
		}
	if (ok == 0)
		printf("id does not exist");
}

int delete_signal(signal signals[], int number_of_signals, int id)
{
	int position = -1;
	int i = 0;
	for (i = 0; i < number_of_signals; i++)
		if (signals[i].id == id)
			position = i;
	if (position != -1)
	{
		for (i = position; i < number_of_signals; i++)
			signals[i] = signals[i + 1];
		number_of_signals--;
	}
	else
		printf("id does not exist");
	return number_of_signals;
}

void list(signal signals[], int number_of_signals)
{
	for (int i = 0; i < number_of_signals; i++)
		printf("id: %d, modulatedSignal: %s, type: %s, priorityNumber: %d\n", signals[i].id, signals[i].modulatedSignal,
		signals[i].type, signals[i].priorityNumber);
}

void list_type(signal signals[], int number_of_signals, char type[])
{
	for (int i = 0; i < number_of_signals; i++)
		if (strcmp(signals[i].type, type) == 0)
			printf("id: %d, modulatedSignal: %s, type: %s, priorityNumber: %d\n", signals[i].id, signals[i].modulatedSignal,
				signals[i].type, signals[i].priorityNumber);
}

void print_menu()
{
	printf("\nCommand formats: \n");
	printf("   -> add <id>, <modulatedSignal>, <type>, <priorityNumber>\n");
	printf("   -> update <id>, <newModulatedSignal>, <newType>, <newPriorityNumber>\n");
	printf("   -> delete <id>\n");
	printf("   -> list\n");
	printf("   -> list <type>\n\n");
}


int run_menu()
{
	int number_of_signals;
	number_of_signals = 0;
	char command[255];
	char parameters[6][25];
	signal signals[101];
	//DynamicSignals signals;
	while (1)
	{
		print_menu();
		scanf("%[^\n]%*c", command);
		if (strcmp(command, "exit") == 0)
			return 0;
		else
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
			if (strcmp(parameters[0], "add") == 0)
			{
				if (counter == 5)
				{
					number_of_signals = add(signals, number_of_signals, atoi(parameters[1]), parameters[2], parameters[3], atoi(parameters[4])); //id, signal, type, priority
					//length++;
				}
				else
					printf("Invalid command\n");
			}
			else
			{
				if(strcmp(parameters[0], "update") == 0)
					if (counter == 5)
					{
						update(signals, number_of_signals, atoi(parameters[1]), parameters[2], parameters[3], atoi(parameters[4])); //id, signal, type, priority
					}
					else
						printf("Invalid command\n");
				else
				{
					if (strcmp(parameters[0], "list") == 0)
					{
						if (counter == 1)
							list(signals, number_of_signals);
						else
							if (counter == 2)
								list_type(signals, number_of_signals, parameters[1]); // type
							else
								printf("Invalid command\n");
					}
					else
					{
						if (strcmp(parameters[0], "delete") == 0 && counter == 2)
						{
							number_of_signals = delete_signal(signals, number_of_signals, atoi(parameters[1]));
						}
						else
							printf("Invalid command\n");
					}
				}
			}
		}
	}
}

/*int main()
{
	run_menu();
	return 0;
}*/

