#pragma once

#include <QWidget>
#include "ui_myListGUI.h"

class myListGUI : public QWidget
{
	Q_OBJECT

private:
	QAbstractItemModel* model;

public:
	myListGUI(QAbstractItemModel* model, QWidget *parent = Q_NULLPTR);
	~myListGUI();

private:
	Ui::myListGUI ui;
};
