#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "QVector"
#include <QtWidgets/QDoubleSpinBox>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;
    QVector<QDoubleSpinBox*> v;
};

#endif // FORM_H
