#pragma once
#include <qabstractitemmodel.h>
#include "Repository.h"

class myListModel :
	public QAbstractTableModel
{
private:
	//Repository &repo;
	vector<TElem> myList;
public:
	myListModel(vector<TElem> myList);

	int rowCount(const QModelIndex &parent = QModelIndex()) const;

	int columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	~myListModel();
};

