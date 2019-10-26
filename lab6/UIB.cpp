#include "UIB.h"
#include "UI.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;


void UIB::run()
{
	int currentFootagePosition = 0;
	while (true)
	{
		std::string command, parameters[6];
		int counter = 0;
		UIB::printMenu();
		cout << "Enter command: ";
		getline(cin, command);
		//cout << "\n" << command << "\n";
		//cin.ignore();
		if (command == "exit")
			break;
		
		//UIB::splitCommands(parameters, command, counter);

		//cout << parameters[0] << " " << parameters[1] <<" " << counter << "\n";

		if (command == "next")
		{
			
			UIB::printFootage(this->controller.getRepository().getElements()[currentFootagePosition]);
			if (currentFootagePosition == this->controller.getControllerElements().getNumberOfFragments() - 1)
				currentFootagePosition = 0;
			else
				currentFootagePosition++;
		}
		else
		{
			if (command == "mylist")
				this->list();
			else
			{
				UIB::splitCommands(parameters, command, counter);
				//cout << parameters[0] << " " << parameters[1] << " " << counter << "\n";

				if (parameters[0] == "save" and counter == 2)
				{
					if (currentFootagePosition == 0)
					{
						if (this->controller.getRepository().getElements()[this->controller.getRepository().getElements().getNumberOfFragments() - 1].getTitle() == parameters[1])
							this->myList.addFootage(this->controller.getRepository().getElements()[this->controller.getRepository().getElements().getNumberOfFragments() - 1]);
					
					}
					else
					{
						if (this->controller.getRepository().getElements()[currentFootagePosition - 1].getTitle() == parameters[1])
							this->myList.addFootage(this->controller.getRepository().getElements()[currentFootagePosition - 1]);
						else
						{
							bool ok = false;
							for (int i = 0; i < this->controller.getRepository().getElements().getNumberOfFragments(); i++)
								if (this->controller.getRepository().getElements()[i].getTitle() == parameters[1])
								{
									ok = true;
									this->myList.addFootage(this->controller.getRepository().getElements()[i]);
								}
							if (ok == false)
								std::cout << "Title does not exist\n";
						}		
					}
				}
				else
				{
					if (parameters[0] == "list" and counter == 3)
					{
						int timesAccessed = stoi(parameters[2]);
						this->printLocation(parameters[1], timesAccessed);
					}
					else
						if (parameters[0] == "mode" and parameters[1] == "A")
						{
							this->changeMode();
							return;
						}
							
						else
							std::cout << "Invalid command\n";
				}
			}
		}
		
	}
}

void UIB::changeMode()
{
	UI newUI(this->controller);
	newUI.run();
}

void UIB::printMenu()
{
	std::cout << "Command formats:\n";
	std::cout << "  -> next\n";
	std::cout << "  -> save <title>\n";
	std::cout << "  -> list <location>, <timesAccessed>\n";
	std::cout << "  -> mylist\n";
	cout << "  -> exit\n\n";
}

void UIB::splitCommands(std::string parameters[], std::string & command, int & counter)
{
	std::string commandDelimiter = " ";
	size_t position = command.find(commandDelimiter); //position of the first appearence of the delimiter
	std::string token = command.substr(0, command.find(commandDelimiter)); //first "word"
	command.erase(0, position + commandDelimiter.length()); // "erases" the word before the delimiter from command
	parameters[counter++] = token;

	std::string delimiter = ", ";
	//size_t position = 0;
	//std::string token;
	while ((position = command.find(delimiter)) != std::string::npos) {
		std::string token = command.substr(0, position);
		//std::cout << token << std::endl;
		parameters[counter] = token;
		counter++;
		command.erase(0, position + delimiter.length());
	}
	parameters[counter++] = command;
}

void UIB::printFootage(TElem & footage)
{
	cout << "title: " << footage.getTitle() << ", ";
	cout << "location: " << footage.getLocation() << ", ";
	cout << "timeOfCreation: " << footage.getTimeOfCreation() << ", ";
	cout << "timesAccessed: " << footage.getTimesAccessed() << ", ";
	cout << "footagePreview: " << footage.getFootagePreview() << "\n";
}

void UIB::list()
{
	for (int i = 0; i < this->myList.getNumberOfFragments(); i++)
	{
		cout << "title: " << this->myList[i].getTitle() << ", ";
		cout << "location: " << this->myList[i].getLocation() << ", ";
		cout << "timeOfCreation: " << this->myList[i].getTimeOfCreation() << ", ";
		cout << "timesAccessed: " << this->myList[i].getTimesAccessed() << ", ";
		cout << "footagePreview: " << this->myList[i].getFootagePreview() << "\n";
	}
}

void UIB::printLocation(std::string & location, int & timesAccessed)
{
	for (int i = 0; i < this->controller.getRepository().getElements().getNumberOfFragments(); i++)
		if (this->controller.getRepository().getElements()[i].getLocation() == location and this->controller.getRepository().getElements()[i].getTimesAccessed() < timesAccessed)
			UIB::printFootage(this->controller.getRepository().getElements()[i]);
}

UIB::~UIB()
{
}
