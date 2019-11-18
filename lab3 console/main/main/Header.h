#pragma once

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

DynamicSignals * initialize(int);
void addSignal(DynamicSignals, signal);
void destroyArray(DynamicSignals);
int run_menu();
