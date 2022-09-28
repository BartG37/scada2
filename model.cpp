#include "model.h"
#include "ser.h"
#include "mainwindow.h"

model::model(QThread *parent) : QThread(parent)
{
    qDebug() << "model konstruktor";
    values1 = new QVector<double>(ser::values_size,0.0);
    as2=new QThread;

}

    void model::run()
    {

        while(!isFinishing)

        {
        qDebug() << "model::run: ";
        as2->msleep(1000);
        setdata();

        }
    }

model::~model()
{
    qDebug() << "model destruktor";

    isFinishing=1;
    quit();
    wait();
    delete as2;
    delete values1;

}

void model::setdata()
{
    if (1)
    {
    qDebug() << "model::setdata: ";
    mutex.lock();

    for( int i=0; i<ser::values_size; ++i)
    {
        (*values1)[i]=static_cast<double>(serItm2->pocket.field.mdb_reg[i]);

    }
    notify();
    mutex.unlock();
    qDebug() << "model::setdata - po: ";
    }
}

void model::addObjects(ser* ser_n,MainWindow* MainWindow_n)
{
    qDebug() << "model::addObjects: ";
    serItm2 = ser_n;
    mainwindowItm = MainWindow_n;

}

void model::notify()
{
    qDebug() << "model::notify: ";
    mainwindowItm->update();
    qDebug() << "model::notify - po";
}

void model::processing()
{
    qDebug() << "model::processing: ";
    mutex.lock();

    for( int i=0; i<ser::values_size; ++i)
    {
//        _sleep(50);
    }

    mutex.unlock();
    qDebug() << "model::processing - po: ";
}
