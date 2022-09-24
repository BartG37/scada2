#include "ser.h"

ser::ser(QObject *parent) : QObject(parent)
{
    qDebug() << "ser-konstruktor: ";
    pocket={};
//    udpSocket = new QUdpSocket(this);
//    udpSocket->bind(QHostAddress::LocalHost, 5000);
//    connect(udpSocket, SIGNAL(readyRead()),this, SLOT(read_on()));

   tcpSocket = new QTcpSocket(this);
   connect(tcpSocket, SIGNAL(readyRead()),this, SLOT(read_on()));

}

    ser::~ser()
    {
      qDebug() << "ser-destruktor: ";
        if (udpSocket!=nullptr)
            delete udpSocket;
        if (tcpSocket!=nullptr)
        {
        tcpSocket->disconnectFromHost();
        delete tcpSocket;
        }
    }
void ser::start(QString adresn)
{
    qDebug() << "ser::start(): ";

//    if (isConnected())
//    tcpSocket->disconnectFromHost();

    tcpSocket->connectToHost(QHostAddress(adresn),502);
     if (tcpSocket->waitForConnected(3000))
         qDebug() << "tcpSocket ok: ";
     else
         qDebug() << "tcpSocket not ok: ";

    emit writeFinish();
}

bool ser::isConnected()
{
    return (tcpSocket->state() == tcpSocket->ConnectedState);

}


void ser::read_on()
{
qDebug() << "read_on";
    dat = tcpSocket->read(pocket.raw, sizeof(pocket.raw));
    qDebug() << "indata: " << pocket.field.tid<< pocket.field.pid<< pocket.field.offset<< pocket.field.device<< pocket.field.fcnNo<< pocket.field.dat_lenght;
    qDebug() << "indata: " <<pocket.field.mdb_reg[0]<<pocket.field.mdb_reg[1];
    qDebug() << "indata: " << dat;

    emit writeFinish();
}


void ser::write_on()
{
 qDebug() << "write_on";
 char outdata[40];
 outdata[0]=0x00;
 outdata[1]=0x01;
 outdata[2]=0x00;
 outdata[3]=0x00;
 outdata[4]=0x00;
 outdata[5]=0x06;
 outdata[6]=0xFF;
 outdata[7]=0x03;
 outdata[8]=0x00;
 outdata[9]=0x00;
 outdata[10]=0x00;
 outdata[11]=0x0A;

 dat = tcpSocket->write(outdata, 30);
 qDebug() << "dat: " << dat;



}

void ser::processing()
{

    isConnected() ? write_on() : start(adres);
    ++cv;

}





