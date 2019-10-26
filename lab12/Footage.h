#pragma once
#include <iostream>

//typedef Footage TElem;

class Footage
{
private:
	std::string title;
	std::string location;
	std::string timeOfCreation;
	std::string footagePreview;
	int timesAccessed;
public:
	Footage();
	Footage(const std::string& Title, const std::string& Location, const std::string& Date, int& Accessed, const std::string& Preview);
	std::string getTitle() const { return title; }
	std::string getLocation() const { return location; }
	std::string getTimeOfCreation() const { return timeOfCreation; }
	int getTimesAccessed() const { return timesAccessed; }
	std::string getFootagePreview() const { return footagePreview;  }

	void setTitle(std::string newTitle) { this->title = newTitle; }
	void setLocation(std::string newLocation) { this->location = newLocation;  }
	void setTimeOfCreation(std::string newTimeOfCreation) { this->timeOfCreation = newTimeOfCreation;  }
	void setTimesAccessed(int newTimesAccessed) { this->timesAccessed = newTimesAccessed;  }
	void setFootagePreview(std::string newFootagePreview) { this->footagePreview = newFootagePreview;  }

	std::string footageString();
	~Footage();

};

