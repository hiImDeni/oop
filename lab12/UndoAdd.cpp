#include "UndoAdd.h"



UndoAdd::UndoAdd(TElem added, Repository* repo) : repository{ repo }, addedFootage{added}
{
}

void UndoAdd::undo()
{
	repository->deleteRepository(addedFootage.getTitle());
}

void UndoAdd::redo()
{
	repository->add(addedFootage);
}


UndoAdd::~UndoAdd()
{
}
