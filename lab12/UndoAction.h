#pragma once
#include "Repository.h"

class UndoAction
{
public:
	UndoAction();
	virtual void undo() = 0;
	virtual void redo() = 0;
	//virtual void redo() = 0;
	~UndoAction();
};

