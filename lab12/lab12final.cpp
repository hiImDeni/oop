#include "lab12final.h"

lab12final::lab12final(ControllerA& ctrl, QWidget *parent)
	: QMainWindow(parent), controller{ctrl}
{
	ui.setupUi(this);
	populateModeA();

	nextVector.footages = controller.getControllerElements();
	nextVector.index = 0;

	//ui.currentEdit->setText(QString::fromStdString(nextVector.footages[0].footageString()));

	connectSlots();
	//QObject::connect(ui.addButton, &QPushButton::clicked, this, &lab12final::add);

}

void lab12final::populateModeA()
{
	vector<TElem> elements = this->controller.getControllerElements();
	for (auto &footage : elements)
	{
		QString string = QString::fromLocal8Bit(footage.footageString().c_str());

		ui.list->addItem(string);
		
		//list->addItem(string);
	}
}

void lab12final::populateModeB()
{
	for (auto &element : myList)
		ui.myList->addItem(QString::fromStdString(element.footageString()));
}

void lab12final::connectSlots()
{
	QObject::connect(ui.addButton, &QPushButton::clicked, this, &lab12final::add);
	QObject::connect(ui.deleteButton, &QPushButton::clicked, this, &lab12final::remove);
	QObject::connect(ui.updateButton, &QPushButton::clicked, this, &lab12final::update);
	QObject::connect(ui.nextButton, &QPushButton::clicked, this, &lab12final::next);
	QObject::connect(ui.saveButton, &QPushButton::clicked, this, &lab12final::save);
	QObject::connect(ui.filterButtonB, &QPushButton::clicked, this, &lab12final::filter);
	QObject::connect(ui.myListButton, &QPushButton::clicked, this, &lab12final::myListSlot);
	QObject::connect(ui.undoButton, &QPushButton::clicked, this, &lab12final::undoSlot);
	QObject::connect(ui.redoButton, &QPushButton::clicked, this, &lab12final::redoSlot);

	//shortcut for undo
	undoShortcut = new QShortcut(QKeySequence(tr("Ctrl+Z")), ui.undoButton);
	QObject::connect(undoShortcut, SIGNAL(activated()), this, SLOT(undoSlot()));

	//shortcut for redo
	redoShortcut = new QShortcut(QKeySequence(tr("Ctrl+Y")), ui.redoButton);
	QObject::connect(redoShortcut, SIGNAL(activated()), this, SLOT(redoSlot()));
}

void lab12final::add()
{
	QString title = ui.titleEdit->text();
	QString location = ui.locationEdit->text();
	QString timeCreation = ui.timeCreationEdit->text();
	QString accessed = ui.timesAccessedEdit->text();
	QString preview = ui.previewEdit->text();
	int timesAccessed = accessed.toInt();
	try
	{
		this->controller.addController(title.toStdString(), location.toStdString(), timeCreation.toStdString(), timesAccessed, preview.toStdString());
		ui.list->clear();
		populateModeA();
	}
	catch (nameError& Exception)
	{
		QMessageBox* errorMessage = new QMessageBox{};
		errorMessage->setWindowTitle("Error");
		errorMessage->setText(QString::fromStdString(Exception.getMessage()));
		errorMessage->show();
	}
	catch (signalError& Exception)
	{
		QMessageBox* errorMessage = new QMessageBox{};
		errorMessage->setWindowTitle("Error");
		errorMessage->setText(QString::fromStdString(Exception.getMessage()));
		errorMessage->show();
	}
	catch (exception& Exception)
	{
		QMessageBox* errorMessage = new QMessageBox{};
		errorMessage->setWindowTitle("Error");
		errorMessage->setText(QString::fromStdString(Exception.what()));
		errorMessage->show();
	}
}

void lab12final::remove()
{
	QString title = ui.titleEdit->text();

	try {
		this->controller.deleteController(title.toStdString());
		ui.list->clear();
		populateModeA();
	}
	catch (nameError& Exception)
	{
		QMessageBox* errorMessage = new QMessageBox{};
		errorMessage->setWindowTitle("Error");
		errorMessage->setText(QString::fromStdString(Exception.getMessage()));
		errorMessage->show();
	}
	catch (signalError& Exception)
	{
		QMessageBox* errorMessage = new QMessageBox{};
		errorMessage->setWindowTitle("Error");
		errorMessage->setText(QString::fromStdString(Exception.getMessage()));
		errorMessage->show();
	}
	catch (exception& Exception)
	{
		QMessageBox* errorMessage = new QMessageBox{};
		errorMessage->setWindowTitle("Error");
		errorMessage->setText(QString::fromStdString(Exception.what()));
		errorMessage->show();
	}
	
}

void lab12final::update()
{
	QString title = ui.titleEdit->text();
	QString location = ui.locationEdit->text();
	QString timeCreation = ui.timeCreationEdit->text();
	QString accessed = ui.timesAccessedEdit->text();
	QString preview = ui.previewEdit->text();
	int timesAccessed = accessed.toInt();

	try{
		controller.updateController(title.toStdString(), location.toStdString(), timeCreation.toStdString(), timesAccessed, preview.toStdString());
		ui.list->clear();
		populateModeA();
	}
	catch (nameError& Exception)
	{
		QMessageBox* errorMessage = new QMessageBox{};
		errorMessage->setWindowTitle("Error");
		errorMessage->setText(QString::fromStdString(Exception.getMessage()));
		errorMessage->show();
	}
	catch (signalError& Exception)
	{
		QMessageBox* errorMessage = new QMessageBox{};
		errorMessage->setWindowTitle("Error");
		errorMessage->setText(QString::fromStdString(Exception.getMessage()));
		errorMessage->show();
	}
	catch (exception& Exception)
	{
		QMessageBox* errorMessage = new QMessageBox{};
		errorMessage->setWindowTitle("Error");
		errorMessage->setText(QString::fromStdString(Exception.what()));
		errorMessage->show();
	}
}

void lab12final::filter()
{
	string location = ui.locationFilterEdit->text().toStdString();
	int accessed = ui.accessedFilterEdit->text().toInt();

	if (location == "" || accessed < 0)
	{
		QMessageBox* errorMessage = new QMessageBox{};
		errorMessage->setWindowTitle("Error");
		errorMessage->setText("Invalid data");
		errorMessage->show();
		return;
	}

	//QWidget *newWidget = new QWidget{};
	//newWidget->setWindowTitle("Filter footages");

	QListWidget *filterList = new QListWidget{};
	for (auto &element : controller.getControllerElements())
		if (element.getLocation() == location && element.getTimesAccessed() < accessed)
			filterList->addItem(QString::fromStdString(element.footageString()));
	filterList->setWindowTitle("Filter footages");
	filterList->show();
}

void lab12final::next()
{
	nextVector.footages = controller.getControllerElements();
	nextVector.index++;
	if (nextVector.index == nextVector.footages.size())
		nextVector.index = 0;
	ui.currentEdit->setText(QString::fromStdString(nextVector.footages[nextVector.index].footageString()));
}

void lab12final::save()
{
	QString title = ui.titleBEdit->text();
	std::string saveTitle = title.toStdString();

	std::vector<TElem> elements = controller.getControllerElements();
	for (auto &element : elements)
	{
		if (element.getTitle() == saveTitle)
		{
			myList.push_back(element);
			ui.myList->clear();
			populateModeB();
			return;
		}
	}
	QMessageBox* errorMessage = new QMessageBox{};
	errorMessage->setWindowTitle("Error");
	errorMessage->setText("Title does not exist");
	errorMessage->show();
}

void lab12final::myListSlot()
{
	myListModel* model = new myListModel{ myList };
	myListGUI* myListWindow = new myListGUI{ model };
	myListWindow->show();
}

void lab12final::undoSlot()
{
	try {
		controller.executeUndo();
		ui.list->clear();
		populateModeA();
	}
	catch (std::exception &e)
	{
		QMessageBox* errorMessage = new QMessageBox{};
		errorMessage->setWindowTitle("Error");
		errorMessage->setText("Nothing to undo");
		errorMessage->show();
	}
}

void lab12final::redoSlot()
{
	try {
		controller.executeRedo();
		ui.list->clear();
		populateModeA();
	}
	catch (std::exception &e)
	{
		QMessageBox* errorMessage = new QMessageBox{};
		errorMessage->setWindowTitle("Error");
		errorMessage->setText("Nothing to redo");
		errorMessage->show();
	}
}

