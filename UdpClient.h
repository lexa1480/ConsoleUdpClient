#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <iostream>
#include <ip_st_x3.h>

class UdpClient : public QObject
{
    Q_OBJECT

private:
    ip_st_x::CStPlugMain m_plugIpSt;
    ip_st_x::CStPlugClient m_plugClient;

public:
    UdpClient(ip_st_x::CStPlugMain &m_plugIpSt, ip_st_x::CStPlugClient &m_plugClient, QObject* pwgt = 0);

public slots:
    void exitHandler();
};

#endif // UDPCLIENT_H
