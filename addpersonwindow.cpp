#include "addpersonwindow.h"
#include "ui_addpersonwindow.h"

AddPersonWindow::AddPersonWindow(Database * db, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::AddPersonWindow), _data(db)
{
    ui->setupUi(this);
}

AddPersonWindow::~AddPersonWindow()
{
    delete ui;
}

void AddPersonWindow::on_cButton_clicked()
{
    this->close();
}
