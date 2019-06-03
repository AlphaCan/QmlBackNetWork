#include "treemodel.h"


treemodel::treemodel(QObject *parent):QAbstractItemModel(parent)
{
//    QList<QVariant> root;
//    root << "st" << "er" << "we";
//    rootdata = new TreeData(root);
//    setupModelData(rootdata);
    rootdata = new TreeData({"A","B","C"});
    auto item1 = new TreeData({"a","b","c"});
    auto item2 = new TreeData( { "aa", "bb","cc" } );
    auto item3 = new TreeData( { "aaa", "bbb","ccc" } );

    rootdata->appendChild(item1);
    item1->appendChild(item2);
    item2->appendChild(item3);
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
//    if (parent.isValid())
//        return static_cast<TreeData*>(parent.internalPointer())->columnCount();
//    else
//        return rootdata->columnCount();
    Q_UNUSED(parent);
    return 3;
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


    switch (role) {
    case NameRole:
        return static_cast<TreeData*>(index.internalPointer())->data(0);
    case IpRole:
        return static_cast<TreeData*>(index.internalPointer())->data(1);
    case DescriptionRole:
        return static_cast<TreeData*>(index.internalPointer())->data(2);
    case Qt::DisplayRole:
        return static_cast<TreeData*>(index.internalPointer())->data(index.column());
    default:return QVariant();

    }

//    if (role != Qt::DisplayRole)
//        return QVariant();

//    TreeData *item = static_cast<TreeData*>(index.internalPointer());

//    return item->data(index.column());
}

QHash<int,QByteArray> treemodel::roleNames() const{
    QHash<int, QByteArray> roles(QAbstractItemModel::roleNames());
    roles[NameRole] = "name";
    roles[IpRole] = "ip";
    roles[DescriptionRole] = "description";
    return roles;
}




























