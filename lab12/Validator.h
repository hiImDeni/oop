#pragma once
#include "Footage.h"
#include "exceptions.h"

typedef Footage TElem;

class Validator
{
public:
	Validator();
	static void validateFootage(TElem footage);
	~Validator();
};

