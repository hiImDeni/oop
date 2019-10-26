#include "UndoRemove.h"



UndoRemove::UndoRemove(TElem deleted, Repository* repo) : repository{ repo }, deletedFootage{ deleted }
{
}

void UndoRemove::undo()
{
	repository->add(deletedFootage);
}

void UndoRemove::redo()
{
	repository->deleteRepository(deletedFootage.getTitle());
}


UndoRemove::~UndoRemove()
{
}
