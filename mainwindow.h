#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qDebug>
#include <QVector>
#include <bg.h>
#include "./ui_mainwindow.h"


//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE


class model;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setTagItem(void);
    void setTagItem_cfg(void);
    void addObjects(model* modeln);
    void update();
public slots:
    void pushButton_on();
    void show()
    {
        qDebug() << "show: ";
        QMainWindow::show();
    };


public:
    Ui::MainWindow *ui=nullptr;
    QVector<bg*> TagItem;

private:
    model* modelItm=nullptr;



};





#endif // MAINWINDOW_H
