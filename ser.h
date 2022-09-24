#ifndef SER_H
#define SER_H

#include <QObject>
#include <QDebug>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QTcpSocket>
#include <QtEndian>



class ser : public QObject
{
    Q_OBJECT

    qint64 dat=0;
    QString adres="127.0.0.1";
    quint16 port=502;
    QUdpSocket* udpSocket=nullptr;
    QTcpSocket* tcpSocket=nullptr;

public:
    static const short values_size=100;
    union pocket_u
    {
        char raw[values_size+10];
       #pragma pack(1)
       struct
       {
       qint16_be tid;
       qint16_be pid;
       qint16_be offset;
       uint8_t device;
       uint8_t fcnNo;
       uint8_t dat_lenght;
       qint16_be mdb_reg[values_size];
       }field;
    };

    explicit ser(QObject *parent = nullptr);

    ~ser();

    bool isConnected(void );

public slots:
    void read_on();
    void write_on();
    void processing();
    void start(const QString adresn = "127.0.0.1");


signals:
    void writeFinish();

public:
    pocket_u pocket;
//    model* modelIt=nullptr;
    int cv=5;
};



#endif // SER_H
