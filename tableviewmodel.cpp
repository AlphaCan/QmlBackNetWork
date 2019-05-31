#include "tableviewmodel.h"

TableViewModel::TableViewModel():QAbstractTableModel (0)
{

}

int TableViewModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return tabview_data.size();
}

int TableViewModel::columnCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return 3;
}

QVariant TableViewModel::data(const QModelIndex &index, int role) const{
    return tabview_data[index.row()][role];
}


void TableViewModel::Add(QString name,QString ip,QString description){
    beginInsertRows(QModelIndex(),tabview_data.size(),tabview_data.size());
    QVector<QString> list;
    list.push_back(name);
    list.push_back(ip);
    list.push_back(description);
    tabview_data.push_back(list);
    endInsertRows();
}

void TableViewModel::Set(int row,int colum,QString text){
    if((row == -1)||(colum == -1)){
        return;
    }
    beginResetModel();
    tabview_data[row][colum] = text;
    endResetModel();
}


void TableViewModel::Del(void){
    if(tabview_data.size()<=0)return;
    beginRemoveRows(QModelIndex(),tabview_data.size()-1,tabview_data.size()-1);
    tabview_data.removeLast();
    endRemoveRows();
}

void TableViewModel::Refresh(void){
    beginResetModel();
    endResetModel();
}


