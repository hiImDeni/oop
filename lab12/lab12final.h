#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lab12final.h"
#include "ControllerA.h"
#include "myListModel.h"
#include "myListGUI.h"
#include <QListWidget>
#include <qmessagebox.h>
#include <qshortcut.h>

typedef struct
{
	vector<TElem> footages;
	int index;
}iterate;

class lab12final : public QMainWindow
{
	Q_OBJECT

public:
	lab12final(ControllerA& ctlr, QWidget *parent = Q_NULLPTR);

private:
	Ui::lab12finalClass ui;
	ControllerA controller;

	vector<TElem> myList;
	iterate nextVector;

	QShortcut* undoShortcut;
	QShortcut* redoShortcut;

	void populateModeA();
	void populateModeB();
	void connectSlots();
public slots:
	void add();
	void remove();
	void update();
	void filter();
	void next();
	void save();
	void myListSlot();
	void undoSlot();
	void redoSlot();
	//void filterLocation();
};
