#include "addcarwindow.h"
#include "ui_addcarwindow.h"

AddCarWindow::AddCarWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddCarWindow)
{
    ui->setupUi(this);
}

AddCarWindow::~AddCarWindow()
{
    delete ui;
}
