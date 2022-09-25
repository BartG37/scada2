#include "mainwindow.h"


MainWindow::MainWindow(ser* ser1, model* model1, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ser1(ser1)
    , model1(model1)
{
    qDebug() << "MainWindow-konstruktor: ";
    ui->setupUi(this);
    QVector<bg*> TagItem(25,nullptr);
    qDebug() << TagItem.size();
    setTagItem();
    setTagItem_cfg();
    //connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(pushButton_on()));
    connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(fcn1()));
//    connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(fcn2()));



}

MainWindow::~MainWindow()
{
    qDebug() << "~MainWindow(): ";
    delete ui;
//    delete ser1;
//    delete model1;

}

void MainWindow::pushButton_on()
{
    qDebug() << "pushButton_on: ";

}

void MainWindow::fcn1() {model1->setdata(ser1->pocket);}

void MainWindow::fcn2() {model1->setdata(ser1->pocket);}

void MainWindow::setTagItem()
{

    TagItem.push_back(ui->G10FT101);
    TagItem.push_back(ui->G10FT102);
    TagItem.push_back(ui->G10FT103);
    TagItem.push_back(ui->G10FT104);
}

void MainWindow::setTagItem_cfg()
{
    TagItem[0]->tag->setText("G10FT101 m3/h");
    TagItem[1]->tag->setText("G10FT102 m3/h");
    TagItem[2]->tag->setText("G10PT101 Bar");
    TagItem[3]->tag->setText("G10PT101 Bar");
}
