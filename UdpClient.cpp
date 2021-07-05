#include "UdpClient.h"
#include <QTime>

UdpClient::UdpClient(QObject* pwgt) : QObject(pwgt){

    pudp = new QUdpSocket(this);
    pudp->bind(2021);

    connect(pudp, SIGNAL(readyRead()), SLOT(slotProcessData()));
}


void UdpClient::slotProcessData(){

    QByteArray baData;

    do{
        baData.resize(pudp->pendingDatagramSize());
        pudp->readDatagram(baData.data(), baData.size());
    } while(pudp->hasPendingDatagrams());

    QTime time;

    QDataStream in(&baData, QIODevice::ReadOnly);
    in >> time;

    QTextStream cout(stdout);
    cout << "Accept Time: " << time.toString() << endl;
}
