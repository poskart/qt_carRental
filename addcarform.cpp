#include "addcarform.h"
#include "ui_addcarform.h"

AddCarForm::AddCarForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddCarForm)
{
    ui->setupUi(this);
}

AddCarForm::~AddCarForm()
{
    delete ui;
}
