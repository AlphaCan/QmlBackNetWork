#ifndef TREEDATA_H
#define TREEDATA_H

#include <QList>
#include <QVariant>

class TreeData
{
public:
    explicit TreeData(const QList<QVariant> &data, TreeData *parentItem = 0);

    ~TreeData();

    void appendChild(TreeData *child);

    TreeData *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    TreeData *parentItem();

private:
    QList<TreeData*> m_childItems;
    QList<QVariant> m_itemData;
    TreeData *m_parentItem;
};

#endif // TREEDATA_H
