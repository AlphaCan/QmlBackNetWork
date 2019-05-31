#include "nic.h"


NIC::NIC(QObject *parent) : QObject(parent)
{

}

//扫描网卡，返回扫描结果，返回 -1 表示未扫描到网卡 errbuf为错误信息
int NIC::Find_nic_device(void){
    char errbuf[PCAP_ERRBUF_SIZE];
    return pcap_findalldevs(&alldevs,errbuf);
}







