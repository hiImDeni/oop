#include "lab12final.h"
#include "Repository.h"
#include "FileRepository.h"
#include "ControllerA.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	ifstream config;
	config.open("repo.config");
	std::string command;
	getline(config, command);

	Repository* repo;

	if (command == "in-memory")
		repo = new Repository{};
	else
	{
		size_t position = command.find(" ");
		//std::string command = file.substr(0, file.find(" "));
		command.erase(0, position + 1);
		fstream openFile(command);
		if (openFile.good())
		{
			repo = new FileRepository{ command };
		}
		else
		{
			ofstream newFile(command);
			if (newFile.good())
			{
				repo = new FileRepository{ command };
			}
		}
		/*std::string file = "data.txt";
		repo = new FileRepository{ file };*/
	}

	ControllerA controller{ repo };

	lab12final w{ controller };
	w.show();
	return a.exec();
}
