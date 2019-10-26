#include "FileRepository.h"

using namespace std;


std::istream & operator>>(std::istream & is, TElem & footage)
{
	string line;
	getline(is, line);

	std::string parameters[7], delimiter = ", "; 
	int counter = 0, position = 0;
	while ((position = line.find(delimiter)) != std::string::npos) {
		std::string token = line.substr(0, position);
		parameters[counter] = token;
		counter++;
		line.erase(0, position + delimiter.length());
	}
	parameters[counter++] = line;

	if (counter != 5)
		return is;

	int accessed = stoi(parameters[3]);

	footage.setTitle(parameters[0]);
	footage.setLocation(parameters[1]);
	footage.setTimeOfCreation(parameters[2]);
	footage.setTimesAccessed(accessed);
	footage.setFootagePreview(parameters[4]);

	return is;
}



FileRepository::FileRepository(std::string& File) : Repository{}, dataFile{ File }
{
	//cout << this->dataFile << "\n";
	this->readFromFile();
}

//FileRepository::FileRepository(std::string & File, std::string & output): Repository{output}, dataFile{ File }
//{
//	this->readFromFile();
//}

void FileRepository::readFromFile()
{
	ifstream file;
	file.open(this->dataFile);
	if (file.is_open())
	{
		TElem footage;
		//file >> footage;
		//cout << footage.getTitle() << footage.getTimeOfCreation();
		while (file >> footage)
			this->add(footage);
	}
	file.close();
	//this->storeData();

	//else throw exception("File is not open");
}

void FileRepository::writeToFile()
{
	ofstream file;
	file.open(this->dataFile);

	std::vector<TElem> writeVector = this->getElements();
	for (auto& footage : writeVector)
		file << footage.getTitle() << ", " << footage.getLocation() << ", " << footage.getTimeOfCreation() << ", " << footage.getTimesAccessed() << ", " << footage.getFootagePreview() << "\n";
	file.close();
}

bool FileRepository::add(const TElem & newFootage)
{
	//this->readFromFile();
	Validator::validateFootage(newFootage);
	if (this->findByTitle(newFootage.getTitle()) != -1)
		throw nameError("Title already exists");
	this->elements.push_back(newFootage);
	this->writeToFile();
	return true;
	//this->storeData();
}

TElem FileRepository::update(const std::string & Title, const std::string & newLocation, const std::string & newDate, int & newAccessed, const std::string & newPreview)
{
	//this->readFromFile();
	Validator::validateFootage(Footage(Title, newLocation, newDate, newAccessed, newPreview));
	if (this->findByTitle(Title) == -1)
		throw nameError("Title does not exist");
	TElem beforeUpdate;
	for (auto& footage : this->elements)
		if (footage.getTitle() == Title)
		{
			beforeUpdate = footage;
			footage.setLocation(newLocation);
			footage.setTimesAccessed(newAccessed);
			footage.setTimeOfCreation(newDate);
			footage.setFootagePreview(newPreview);
		}
	this->writeToFile();
	return beforeUpdate;
	//this->storeData();
}

TElem FileRepository::deleteRepository(const std::string & Title)
{
	//this->readFromFile();
	if (this->findByTitle(Title) == -1)
		throw nameError("Title does not exist");
	int position = this->findByTitle(Title);
	TElem deletedFootage = elements[position];
	this->elements.erase(this->elements.begin() + position);
	this->writeToFile();
	return deletedFootage;
	//this->storeData();
}


FileRepository::~FileRepository()
{
}

