#pragma once
#include "UndoAction.h"
class UndoUpdate :
	public UndoAction
{
private:
	TElem beforeUndo;
	TElem updatedFootage;
	Repository* repository;
public:
	UndoUpdate(TElem before, TElem updated, Repository* repo);

	void undo() override;
	void redo() override;

	~UndoUpdate();
};

