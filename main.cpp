#include <QApplication>
#include <QDebug>
#include "mainwindow.h"
#include "ser.h"
#include "model.h"
#include "asyn_connect.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    asyn_connect o_as;
    MainWindow w;
    model omodel;


//    while (!o_as.serItm)
//    qDebug() << "!!!!!!!!!!!!!!!!"<<o_as.serItm;
//    qDebug() << "----------------" <<o_as.serItm;

    omodel.addObjects(o_as.serItm,&w);
    omodel.start();
    w.addObjects(&omodel);

//    a.connect(w.ui->pushButton_2, SIGNAL(clicked()), o_as.serItm, SLOT(write_on()));
//    o_as.connect(&o_as, SIGNAL(finished(ser::pocket_u)), &omodel, SLOT(writeFinish2(ser::pocket_u)));


//    o_as.serItm->connect(o_as.serItm, SIGNAL(writeFinish(pocket)), &omodel, SLOT(writeFinish2(pocket)));
//    o_as.start();
//    o_as.wait();
//    qDebug() << "o_as.start() - po: ";
//     MainWindow::v[0]->tag->setText("G10FT101 [l/h]");
//     MainWindow::v[1]->tag->setText("G10VT102 [mm/s]");
//     MainWindow::v[2]->tag->setText("G10LT103 [mm]");
//     MainWindow::v[3]->tag->setText("G10PT104 [Bar]");

    w.show();
    return a.exec();
}
