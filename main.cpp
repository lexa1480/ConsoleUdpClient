#include <QCoreApplication>
#include "UdpClient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream cout(stdout);
    cout << "!Client!" << endl;

    UdpClient client;

    return a.exec();
}
