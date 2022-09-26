#ifndef BG_H
#define BG_H
#include <QWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>



class bg : public QWidget
{

    Q_OBJECT

public:
    bg( QWidget *parent = nullptr);
    ~bg();
    static int lpbg;



public:
    QDoubleSpinBox *value;
    QLabel *tag;
};


#endif // BG_H

