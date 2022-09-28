#include "mainwindow.h"
#include "model.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    qDebug() << "MainWindow-konstruktor: ";
    ui->setupUi(this);
    QVector<bg*> TagItem(61,nullptr);
    qDebug() << TagItem.size();
    setTagItem();
    setTagItem_cfg();
    ui->listWidget->addItem("nananananna");
    ui->listWidget->addItem("nananananna2");
    ui->listWidget->insertItem(0,"nowy");
    ui->listWidget->insertItem(0,"nowy2");
    ui->listWidget->insertItem(0,"nowy3");
    ui->listWidget->insertItem(0,"nowy4");
    ui->listWidget->insertItem(0,"nowy5");
    ui->listWidget->insertItem(0,"nowy6");
    //nowy2
    ui->listWidget->insertItem(0,"nowy7");

    //connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(pushButton_on()));
//    connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(update()));
//    connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(fcn2()));


}

MainWindow::~MainWindow()
{
    qDebug() << "~MainWindow(): ";
    delete ui;

}

void MainWindow::pushButton_on()
{
    qDebug() << "pushButton_on: ";

}

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
    TagItem[3]->tag->setText("G10PT101 mBar");

}

void MainWindow::update()
{

    for (auto i=0; i<TagItem.size(); ++i)
    TagItem[i]->value->setValue(modelItm->values1->value(i));


}


void MainWindow::addObjects(model *modeln)
{
    modelItm=modeln;
}

