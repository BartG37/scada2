#include "form.h"
#include "ui_form.h"
#include <QtWidgets/QDoubleSpinBox>


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    QDoubleSpinBox *x;
    ui->setupUi(this);
    v.push_back(ui->G10F001);


}

Form::~Form()
{
    delete ui;
}
