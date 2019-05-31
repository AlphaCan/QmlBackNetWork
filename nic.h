#ifndef NIC_H
#define NIC_H

#include <QObject>
#include "pcap.h"


class NIC : public QObject
{
    Q_OBJECT
public:
    explicit NIC(QObject *parent = nullptr);
    Q_INVOKABLE int Find_nic_device(void);

signals:

public slots:

private:
    pcap_if_t *alldevs;
    pcap_if_t *d;
};

#endif // NIC_H
