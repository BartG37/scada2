#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qDebug>
#include <QVector>
#include <bg.h>
#include "./ui_mainwindow.h"
#include <ser.h>
#include <model.h>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(ser* ser1=nullptr, model* model1=nullptr, QWidget *parent = nullptr);
    ~MainWindow();
    void setTagItem(void);
    void setTagItem_cfg(void);

public slots:
    void pushButton_on();
    void fcn1(void);
    void fcn2(void);
    void show()
    {
        qDebug() << "show: ";
        QMainWindow::show();
    };


public:
    Ui::MainWindow *ui=nullptr;
    ser* ser1=nullptr;
    model* model1=nullptr;
    QVector<bg*> TagItem;


};



#endif // MAINWINDOW_H
