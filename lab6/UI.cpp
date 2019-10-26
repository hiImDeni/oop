#include "UI.h"
#include "UIB.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


void UI::run()
{
	/*cout << "Choose mode: ";
	std::string mode;
	getline(cin, mode);
	while (mode != "mode A" and mode != "mode B")
	{
		cout << "Incorrect option.\nChoose mode: ";
		getline(cin, mode);
	}*/

	//if (3 == 3)
	{
		while (true)
		{
			std::string command, parameters[6];
			int counter = 0;
			UI::printMenu();
			cout << "Enter command: ";
			getline(cin, command);
			//cout << "\n" << command << "\n";
			//cin.ignore();
			if (command == "exit")
				break;
			std::string commandDelimiter = " ";
			size_t position = command.find(commandDelimiter); //position of the first appearence of the delimiter
			std::string token = command.substr(0, command.find(commandDelimiter)); //first "word"
			command.erase(0, position + commandDelimiter.length()); // "erases" the word before the delimiter from command
			parameters[counter++] = token;
			UI::splitCommands(parameters, command, counter, position);

			if (parameters[0] == "add" and counter == 6)
			{
				int timesAccessed = stoi(parameters[4]);
				//this->controller.addController(parameters[1], parameters[2], parameters[3], timesAccessed, parameters[5]);
				this->addUI(parameters[1], parameters[2], parameters[3], timesAccessed, parameters[5]);
				//this->list();
			}
			else
			{
				if (parameters[0] == "update" and counter == 6)
				{
					int newTimesAccessed = stoi(parameters[4]);
					this->updateUI(parameters[1], parameters[2], parameters[3], newTimesAccessed, parameters[5]);
					//this->list();
				}
				else
				{
					if (parameters[0] == "delete" and counter == 2)
					{
						this->deleteUI(parameters[1]);
						//this->list();
					}
					else
					{
						if (command == "list")
							this->list();
						else
							if (parameters[0] == "mode" and parameters[1] == "B")
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
}

UI::~UI()
{
}

void UI::changeMode()
{
	UIB newUI(this->controller);
	newUI.run();
}

void UI::addUI(const std::string & Title, const std::string & Location, const std::string & Date, int & Accessed, const std::string & Preview)
{
	if (this->controller.getRepository().getElements().findByTitle(Title) != -1)
	{
		cout << "Title already exists\n";
		return;
	}
	this->controller.addController(Title, Location, Date, Accessed, Preview);
}

void UI::updateUI(const std::string & Title, const std::string & newLocation, const std::string & newDate, int & newAccessed, const std::string & newPreview)
{
	if (this->controller.getRepository().getElements().findByTitle(Title) == -1)
	{
		cout << "Title does not exist\n";
		return;
	}
	this->controller.updateController(Title, newLocation, newDate, newAccessed, newPreview);
}

void UI::deleteUI(const std::string & Title)
{
	int position = this->controller.getRepository().getElements().findByTitle(Title);
	if (position == -1)
	{
		cout << "Title does not exist\n";
		return;
	}
	this->controller.deleteController(position);
}

void UI::printMenu()
{
	cout << "Command formats: \n";
	cout << "  -> add <title>, <location>, <timeOfCreation>, <timesAccessed>, <footagePreview>\n";
	cout << "  -> update <title>, <newLocation>, <newTimeOfCreation>, <newTimesAccessed>, <newFootagePreview>\n";
	cout << "  -> delete <title>\n";
	cout << "  -> list\n";
	cout << "  -> exit\n\n";
}

void UI::splitCommands(std::string parameters[], std::string & command, int & counter, size_t& position)
{
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
	//counter++;
	//cout << counter << "\n";
}

void UI::list()
{
	for (int i = 0; i < this->controller.getRepository().getElements().getNumberOfFragments(); i++)
	{
		cout << "title: " << this->controller.getControllerElements()[i].getTitle() << ", ";
		cout << "location: " << this->controller.getControllerElements()[i].getLocation() << ", ";
		cout << "timeOfCreation: " << this->controller.getControllerElements()[i].getTimeOfCreation() << ", ";
		cout << "timesAccessed: " << this->controller.getControllerElements()[i].getTimesAccessed() << ", ";
		cout << "footagePreview: " << this->controller.getControllerElements()[i].getFootagePreview() << "\n";
	}

}
