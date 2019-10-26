#pragma once
#include "Repository.h"

class ControllerB
{
private:
	Repository repository;
public:
	ControllerB(Repository& repo) : repository{ repo } {}
	~ControllerB();
};

