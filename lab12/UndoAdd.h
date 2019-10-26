#pragma once
#include "UndoAction.h"

class UndoAdd :
	public UndoAction
{
private:
	TElem addedFootage;
	Repository* repository;
public:
	UndoAdd(TElem added, Repository* repo);
	void undo() override;
	void redo() override;
	~UndoAdd();
};

