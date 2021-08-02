#include "UdpClient.h"
#include <QTime>
#include "nmea/nmea_zda.h"

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
    }
    while(pudp->hasPendingDatagrams());

    std::string sPacket(baData.constData(), baData.length());
    nmea::CNmeaPacket packet(sPacket);


    std::cout << "Accept Time Nmea: " << packet.GetString() << std::endl;
}
