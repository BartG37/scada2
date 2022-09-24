#ifndef ASYN_CONNECT_H
#define ASYN_CONNECT_H

#include <QThread>
#include <QDebug>
#include <QMutex>
#include <QTimer>
#include <QVector>
#include <ser.h>
#include <model.h>


class asyn_connect : public QThread
{
    Q_OBJECT
public:
    explicit asyn_connect(QThread *parent = nullptr);
    ~asyn_connect();

    void run() override;
    void addObjects(ser* sern=nullptr, model* modeln=nullptr);


public slots:
    void fcn1(void);
    void fcn2(void);
    void fcn3(void);
//    int exec();

signals:
    void finished(ser::pocket_u);
public:
    QThread* as1=nullptr;
    QTimer* timer=nullptr;
    ser* serItm=nullptr;
    model* modelIts=nullptr;
    QVector<ser*> serIts;
    bool isFinishing=0;

};

#endif // ASYN_CONNECT_H
