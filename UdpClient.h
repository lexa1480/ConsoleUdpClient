#ifndef CLIENTUDP_H
#define CLIENTUDP_H

#include <QObject>
#include <QUdpSocket>

class UdpClient : public QObject
{
    Q_OBJECT

private:
    QUdpSocket* pudp;

public:
    UdpClient(QObject* pwgt = 0);

public slots:
    void slotProcessData();


};

#endif // CLIENTUDP_H
