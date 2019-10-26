#include "myListGUI.h"

myListGUI::myListGUI(QAbstractItemModel* model, QWidget *parent)
	: QWidget(parent), model{model}
{
	ui.setupUi(this);
	ui.footageTableView->setModel(model);
}

myListGUI::~myListGUI()
{
}
