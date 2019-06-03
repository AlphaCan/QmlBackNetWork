#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include "treedata.h"

class treemodel : public QAbstractItemModel
{
    Q_OBJECT
public:

    enum{
      NameRole = Qt::UserRole + 1,
      IpRole = Qt::UserRole + 2,
      DescriptionRole = Qt::UserRole + 3
    };
    treemodel(QObject *parent = 0);
    ~treemodel();
//    void adddata(const treedata &data);
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int columnCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;
    void setupModelData(TreeData *parent);
    QHash<int,QByteArray> roleNames() const override;

private:
//    QList<treedata> treeviewdata;
    TreeData *rootdata;
};

#endif // TREEMODEL_H
