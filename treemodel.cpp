#include "treemodel.h"


treemodel::treemodel(QObject *parent):QAbstractItemModel (parent)
{
    QList<QVariant> root;
    root<<"st"<<"er";
    rootdata = new TreeData(root);
    setupModelData(rootdata);
}

treemodel::~treemodel(){
    delete rootdata;
}

//void treemodel::adddata(const treedata &data){
//    beginInsertRows(QModelIndex(),rowCount(),rowCount());
//    treeviewdata << data;
//    endInsertRows();
//}

QModelIndex treemodel::index(int row, int column, const QModelIndex &parent) const{
    if (!hasIndex(row,column,parent)) {
        return QModelIndex();
    }

    TreeData *parentdata;
    if(!parent.isValid()){
        parentdata = rootdata;
    }else {
        parentdata = static_cast<TreeData*>(parent.internalPointer());
    }
    TreeData *childdata = parentdata->child(row);
    if(childdata){
        return createIndex(row,column,childdata);
    }else {
        return QModelIndex();
    }

}

Qt::ItemFlags treemodel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return QAbstractItemModel::flags(index);
}

QVariant treemodel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootdata->data(section);

    return QVariant();
}

QModelIndex treemodel::parent(const QModelIndex &child) const{
    if (!child.isValid())
        return QModelIndex();

    TreeData *childItem = static_cast<TreeData*>(child.internalPointer());
    TreeData *parentItem = childItem->parentItem();

    if (parentItem == rootdata)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int treemodel::columnCount(const QModelIndex &parent) const{
    if (parent.isValid())
        return static_cast<TreeData*>(parent.internalPointer())->columnCount();
    else
        return rootdata->columnCount();
}

int treemodel::rowCount(const QModelIndex &parent) const{
    TreeData *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootdata;
    else
        parentItem = static_cast<TreeData*>(parent.internalPointer());

    return parentItem->childCount();
}


QVariant treemodel::data(const QModelIndex &index, int role) const{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    TreeData *item = static_cast<TreeData*>(index.internalPointer());

    return item->data(index.column());
}


void treemodel::setupModelData(TreeData *parent){
    for (int i = 0;i<3;i++) {
        QList<QVariant>datas;
        datas<<QString("shebei-%1").arg(i+1)<<QString("leixing-%1").arg(i+1);

        TreeData *primary = new TreeData(datas,parent);
        parent->appendChild(primary);

        for (int j= 1;j<2;j++) {
            QList<QVariant> ds;
            ds<<QString("zishebei-%1").arg(j+1)<<QString("zileixing-%1").arg(j+1);
            primary->appendChild(new TreeData(ds,primary));

        }
    }
}


























