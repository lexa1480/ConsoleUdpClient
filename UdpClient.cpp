#include "UdpClient.h"

UdpClient::UdpClient(ip_st_x::CStPlugMain &m_plugIpSt, ip_st_x::CStPlugClient &m_plugClient, QObject* pwgt) : QObject(pwgt){
    this->m_plugClient = m_plugClient;
    this->m_plugIpSt = m_plugIpSt;
}

void UdpClient::exitHandler(){
    m_plugClient.CloseStClient();
    m_plugIpSt.Stop();
    m_plugIpSt.Free();
}
