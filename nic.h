#ifndef NIC_H
#define NIC_H

#include <QObject>
#include <QNetworkInterface>
#include <QHostInfo>


class NIC : public QObject
{
    Q_OBJECT
public:
    explicit NIC(QObject *parent = nullptr);
    QString localhostname;
    void Get_Host_Name();
    int nic_num = 0;
    QString mynic_name[5];
    QString mynic_ip[5];
    QString mynic_description[5];
    void Get_Nic_Info();

signals:

public slots:


};

#endif // NIC_H
