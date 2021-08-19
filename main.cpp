#include <QCoreApplication>
#include "UdpClient.h"
#include "nmea/nmea_zda.h"

class CStClientProcessor : public ip_st_x::CStClientSubscriber
{
    virtual NVoid OnPacket(NByte* pBufIn, NDword dwSizeIn, ip_st_x::CDataPacketBuffer& dpb){

        std::string sPacket((const char*)(pBufIn));
        nmea::CNmeaPacket packet(sPacket);

        std::cout << "Accept Time Nmea: " << packet.GetString() << std::endl;
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ip_st_x::CStPlugMain m_plugIpSt;
    ip_st_x::CStPlugClient m_plugClient;

    try
    {
        if(!m_plugIpSt.Load())
        {
            throw "Load";
        }
        m_plugIpSt.SetAppName("StTestApp");
        m_plugIpSt.SetSockMcAddr( "234.0.1.0" );
        if(!m_plugIpSt.Start())
        {
            throw "Start";
        }
        if(!m_plugIpSt.GetStClient(m_plugClient))
        {
            throw "Get Client";
        }
        m_plugClient.SetClientName("TestStPlugin");
        if(!m_plugClient.AssignSource("NmeaTime", ip_st_x::ST_READER))
        {
            throw "Assign Source";
        }
        CStClientProcessor m_processor;
        m_plugClient.Subscribe(&m_processor);
        if(!m_plugClient.OpenStClient())
        {
            throw "Open Client";
        }

        UdpClient client(m_plugIpSt, m_plugClient);
        QObject::connect(&a, SIGNAL(aboutToQuit()), &client, SLOT(exitHandler()));
        a.exec();
    }
    catch (char const* str)
    {
        std::cout << "Error: " << str << std::endl;
    }

    return 1;
}
