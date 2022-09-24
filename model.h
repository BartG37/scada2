#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QVector>
#include <QMutex>
#include <QThread>
#include <QDebug>
#include "bg.h"
#include "ser.h"


class model : public QThread
{
    Q_OBJECT

public:

    explicit model(QThread *parent = nullptr);
    ~model();
    void  run();
    QVector<int>& getdata(const QVector<int>&);
    void setdata(const ser::pocket_u&);
    QMutex mutex;
    QVector<float>* values1 = nullptr;
    QThread *as2;
    ser *serItm2;
    void addObjects(ser* sern=nullptr);
public:
    ser::pocket_u pocket;

public slots:
    void processing();
    void writeFinish2(ser::pocket_u pocket);

private:
    bool isFinishing=0;

};



#endif // MODEL_H
