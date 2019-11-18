#pragma once
#include <iostream>

class Footage
{
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

	void setLocation(std::string newLocation) { this->location = newLocation;  }
	void setTimeOfCreation(std::string newTimeOfCreation) { this->timeOfCreation = newTimeOfCreation;  }
	void setTimesAccessed(int newTimesAccessed) { this->timesAccessed = newTimesAccessed;  }
	void setFootagePreview(std::string newFootagePreview) { this->footagePreview = newFootagePreview;  }

	~Footage();
};

