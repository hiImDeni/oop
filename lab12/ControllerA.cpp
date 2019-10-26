#include "ControllerA.h"
#include <vector>
#include <assert.h>
#include "UndoAdd.h"
#include "UndoRemove.h"
#include "UndoUpdate.h"
#include "qmessagebox.h"

bool ControllerA::addController(const std::string & Title, const std::string & Location, const std::string & Date, int & Accessed, const std::string & Preview)
{
	Footage newFootage{ Title, Location, Date, Accessed, Preview };
	this->repository->add(newFootage);
	UndoAction* action = new UndoAdd{ newFootage, repository };
	undos.push_back(action);
	return true;
}

bool ControllerA::updateController(const std::string & Title, const std::string & newLocation, const std::string & newDate, int & newAccessed, const std::string & newPreview)
{
	TElem updatedFootade = this->repository->update(Title, newLocation, newDate, newAccessed, newPreview); //return element before update
	TElem afterUpdate = TElem(Title, newLocation, newDate, newAccessed, newPreview);
	UndoAction* action = new UndoUpdate{ afterUpdate, updatedFootade, repository };
	undos.push_back(action);
	return true;
}

bool ControllerA::deleteController(const std::string & Title)
{
	TElem deletedFootage = this->repository->deleteRepository(Title);
	UndoAction* action = new UndoRemove{ deletedFootage, repository };
	undos.push_back(action);
	return true;
}



vector<TElem>& ControllerA::filter(std::string & location, int & timesAccessed)
{
	vector<TElem> oldVector = this->repository->getElements();
	vector<TElem> filterVector(oldVector.size());

	auto iterator = copy_if(oldVector.begin(), oldVector.end(), filterVector.begin(), [location, timesAccessed](TElem i) { return (i.getLocation() == location && i.getTimesAccessed() < timesAccessed); });
	filterVector.resize(distance(filterVector.begin(), iterator));
	
	return filterVector;
}

void ControllerA::executeUndo()
{
	if (undos.empty())
		throw std::exception("Nothing to undo");
	UndoAction* action = undos.back();
	redos.push_back(action); //only need to redo if an undo is performed
	undos.pop_back();
	action->undo();
}

void ControllerA::executeRedo()
{
	if (redos.empty())
		throw std::exception("Nothing to undo");
	UndoAction* action = redos.back();
	redos.pop_back();
	undos.push_back(action);
	action->redo();
}

ControllerA::~ControllerA()
{
}

