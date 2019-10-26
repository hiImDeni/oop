#include "myListModel.h"



myListModel::myListModel(vector<TElem> myList)
{
	this->myList = myList;
}

int myListModel::rowCount(const QModelIndex & parent) const
{
	return myList.size();
}

int myListModel::columnCount(const QModelIndex & parent) const
{
	return 5;
}

QVariant myListModel::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int column = index.column();
	TElem currentFootage = myList[row];

	if (role == Qt::DisplayRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(currentFootage.getTitle());
		case 1:
			return QString::fromStdString(currentFootage.getLocation());
		case 2:
			return QString::fromStdString(currentFootage.getTimeOfCreation());
		case 3:
			return QString::number(currentFootage.getTimesAccessed());
		case 4:
			return QString::fromStdString(currentFootage.getFootagePreview());
		default:
			break;
		}
	}
	return QVariant();
}

QVariant myListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		switch (section)
		{
		case 0:
			return "Title";
		case 1:
			return "Location";
		case 2:
			return "Time of Creation";
		case 3:
			return "Times Accessed";
		case 4:
			return "Footage Preview";
		default:
			break;
		}
	}
	
	return QVariant();
}


myListModel::~myListModel()
{
}
