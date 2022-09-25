#include "asyn_connect.h"

asyn_connect::asyn_connect(QThread *parent) : QThread(parent)
{
    qDebug() << "asyn_connect - konstruktor: ";
    as1=new QThread(this);
    start();

}

void asyn_connect::run()
{
    qDebug() << "asyn_connect::run(): ";
//    modelIts = new model(nullptr);
    serItm = new ser;
//    serIts.push_back(new ser(nullptr));
    timer = new QTimer(0);
    timer->setInterval(1000);
    timer->connect(timer, SIGNAL(timeout()), serItm, SLOT(processing()));
//    timer->connect(timer, SIGNAL(timeout()), modelIts, SLOT(processing()));
    timer->start();
//    serIts[0]->start("127.0.0.1");
//    serIts[0]->write_on();
//    as1->msleep(2000);
    exec();


    delete serItm;
//    delete timer;
    qDebug() << "asyn_connect::msleep(): - po";

}

void asyn_connect::addObjects(ser* sern, model* modeln)
{

    modelIts=modeln;
    serItm = sern;
}

void asyn_connect::fcn3()
{
    qDebug() << "fcn3: ";

}


asyn_connect::~asyn_connect()
{
    qDebug() << "asyn_connect - destruktor: ";
    isFinishing=1;
    quit();
    wait();
    delete as1;


}

//int asyn_connect::exec()
//{
//    qDebug() << "asyn_connect::exec(): ";
//    QThread::exec();
//    qDebug() << "asyn_connect::exec() - po: ";
//    return 0;

//};


void asyn_connect::fcn1()
{
    qDebug() << "asyn_connect::fcn1(): ";
//    emit finished(serItm->pocket);

}

void asyn_connect::fcn2() {modelIts->setdata(serIts[0]->pocket);}
