#include "Validator.h"



//Validator::Validator()
//{
//}

void Validator::validateFootage(TElem footage)
{
	if (footage.getTitle().size() == 0)
		throw signalError("Invalid data");
	if (footage.getFootagePreview().size() == 0)
		throw signalError("Invalid data");
	if (footage.getLocation().size() == 0)
		throw signalError("Invalid data");
	if (footage.getTimesAccessed() < 0)
		throw signalError("Invalid data");
}


//Validator::~Validator()
//{
//}
