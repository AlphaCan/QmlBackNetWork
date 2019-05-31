#ifndef TABLEVIEWMODEL_H
#define TABLEVIEWMODEL_H
#include <QAbstractTableModel>
#include <QVector>

class TableViewModel:public QAbstractTableModel
{
public:
    TableViewModel();
    int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    Q_INVOKABLE void Add(QString name,QString ip,QString description);
    Q_INVOKABLE void Set(int row,int colum,QString text);
    Q_INVOKABLE void Del(void);
    Q_INVOKABLE void Refresh(void);

private:
    QVector<QVector<QString>> tabview_data;

};

#endif // TABLEVIEWMODEL_H
