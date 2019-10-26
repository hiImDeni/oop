#pragma once
#include "UndoAction.h"

class UndoRemove :
	public UndoAction
{
private:
	TElem deletedFootage;
	Repository* repository;
public:
	UndoRemove(TElem deleted, Repository* repo);

	void undo() override;
	void redo() override;

	~UndoRemove();
};

