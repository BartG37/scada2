#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QVector>
#include <QMutex>
#include <QThread>
#include <QDebug>


class MainWindow;
class ser;

class model :  public QThread
{
    Q_OBJECT

public:

    explicit model(QThread *parent = nullptr);
    ~model();
    QVector<int>& getdata(const QVector<int>&);
    QVector<double>* values1 = nullptr;
    void addObjects(ser* ser_n=nullptr,MainWindow* MainWindow_n=nullptr);
    void setdata();
    void notify();
    void  run() override;
public:

public slots:
    void processing();

private:
    bool isFinishing=0;
    QMutex mutex;
    QThread *as2;
    ser *serItm2=nullptr;
    MainWindow *mainwindowItm=nullptr;
};



#endif // MODEL_H
