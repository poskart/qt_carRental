#include "addcarwindow.h"
#include "ui_addcarwindow.h"

AddCarWindow::AddCarWindow(Database * db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddCarWindow),
    _data(db)
{
    ui->setupUi(this);
}

AddCarWindow::~AddCarWindow()
{
    delete ui;
}

void AddCarWindow::on_cButton_clicked()
{
    this->close();
}
