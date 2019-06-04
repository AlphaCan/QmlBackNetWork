#include "nic.h"


NIC::NIC(QObject *parent) : QObject(parent)
{

}


void NIC::Get_Host_Name(){
    localhostname = QHostInfo::localHostName();
}


void NIC::Get_Nic_Info(){
    foreach(QNetworkInterface interface,QNetworkInterface::allInterfaces()){
        QNetworkAddressEntry entry;
        foreach(entry,interface.addressEntries());//循环赋值
        if((!interface.flags().testFlag(QNetworkInterface::IsLoopBack))&&(interface.flags().testFlag(QNetworkInterface::IsRunning))){//过滤
            mynic_name[nic_num] = interface.humanReadableName();
            mynic_ip[nic_num] = entry.ip().toString();
            mynic_description[nic_num] = interface.name();
            nic_num++;
        }
    }
}






