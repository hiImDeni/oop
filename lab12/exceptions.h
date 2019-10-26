#pragma once
#include <string>

class signalError
{
private:
	std::string error;
public:
	signalError (const std::string& message) : error(message) {}
	std::string getMessage() { return error; }
	~signalError();
};

class nameError
{
private:
	std::string error;
public:
	nameError(const std::string& message) : error(message) {}
	std::string getMessage() { return error; }
	~nameError();
};

