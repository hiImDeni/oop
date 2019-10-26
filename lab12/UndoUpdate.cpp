#include "UndoUpdate.h"



UndoUpdate::UndoUpdate(TElem before, TElem updated, Repository* repo) : repository{ repo }, updatedFootage{ updated }, beforeUndo{ before }
{
}

void UndoUpdate::undo()
{
	//afterUndo = updatedFootage;
	int oldAccessed = updatedFootage.getTimesAccessed();
	repository->update(updatedFootage.getTitle(), updatedFootage.getLocation(), updatedFootage.getTimeOfCreation(), oldAccessed, updatedFootage.getFootagePreview());
}

void UndoUpdate::redo()
{
	int oldAccessed = beforeUndo.getTimesAccessed();
	repository->update(beforeUndo.getTitle(), beforeUndo.getLocation(), beforeUndo.getTimeOfCreation(), oldAccessed, beforeUndo.getFootagePreview());
}


UndoUpdate::~UndoUpdate()
{
}
