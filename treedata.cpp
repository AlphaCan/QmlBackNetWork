#include "treedata.h"

#include <QStringList>


//! [0]
TreeData::TreeData(const QList<QVariant> &data, TreeData *parent)
{
    m_parentItem = parent;
    m_itemData = data;
}
//! [0]

//! [1]
TreeData::~TreeData()
{
    qDeleteAll(m_childItems);
}
//! [1]

//! [2]
void TreeData::appendChild(TreeData *item)
{
    m_childItems.append(item);
}
//! [2]

//! [3]
TreeData *TreeData::child(int row)
{
    return m_childItems.value(row);
}
//! [3]

//! [4]
int TreeData::childCount() const
{
    return m_childItems.count();
}
//! [4]

//! [5]
int TreeData::columnCount() const
{
    return m_itemData.count();
}
//! [5]

//! [6]
QVariant TreeData::data(int column) const
{
    return m_itemData.value(column);
}
//! [6]

//! [7]
TreeData *TreeData::parentItem()
{
    return m_parentItem;
}
//! [7]

//! [8]
int TreeData::row() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<TreeData*>(this));

    return 0;
}
//! [8]






