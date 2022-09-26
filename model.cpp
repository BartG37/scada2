#include "model.h"

model::model(QThread *parent) : QThread(parent)
{
    qDebug() << "model konstruktor";
    values1 = new QVector<double>(ser::values_size,0.0);
//    v.push_back(mw->ui->G10FT101);
//    v.push_back(mw->ui->G10FT102);
    //mw->ui->G10FT101->tag->setText("sdsds");
    as2=new QThread;

//    v[0]->tag->setText("G10FT101 [ccc/h]");

}

    void model::run()
    {

    while(!isFinishing)

    {
    qDebug() << "model::run: ";
    as2->msleep(1000);
    setdata(serItm2->pocket);
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

void model::setdata(const ser::pocket_u& n)
{
    qDebug() << "model::setdata: ";
    mutex.lock();

    for( int i=0; i<ser::values_size; ++i)
    {
        (*values1)[i]=static_cast<double>(n.field.mdb_reg[i]);
//        qDebug() <<(*values1)[i]<<" " <<i<<" " <<n.field.mdb_reg[i];
    }

    mutex.unlock();
    qDebug() << "model::setdata - po: ";
}

void model::addObjects(ser *sern)
{
    qDebug() << "model::addObjects: ";
    serItm2 = sern;

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

void model::writeFinish2(ser::pocket_u pocket)
{
    qDebug() << "model::writeFinish2: ";

    qDebug() << "model::writeFinish2 - po: ";
}
