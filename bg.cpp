#include "bg.h"
#include "QDebug"

int bg::lpbg=0;

bg::bg(QWidget *parent):QWidget(parent)
{
    lpbg++;
    qDebug() << "bg - konstruktor";

    value=new QDoubleSpinBox(parent);
    value->setFont(QFont(QString::fromUtf8("Arial"),20));
    value->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(125, 64, 64, 0), stop:1 rgba(255, 255, 255, 0));"));
    value->setInputMethodHints(Qt::ImhNone);
    value->setFrame(false);
    value->setAlignment(Qt::AlignCenter);
    value->setReadOnly(true);
    value->setButtonSymbols(QAbstractSpinBox::NoButtons);
    value->setKeyboardTracking(false);
    value->setDecimals(1);
    value->setMaximum(1000.0);
    value->setValue(lpbg);

    tag=new QLabel(parent);
    tag->setText("Tag [m3/h]");
    tag->setAlignment(Qt::AlignCenter);


    value->setGeometry(QRect(0, 15, 100, 36));
    tag->setGeometry(QRect(0, 0, 100, 20));


}

bg::~bg()
{
    qDebug() << "bg - destruktor";
    delete tag;
    delete value;

}



