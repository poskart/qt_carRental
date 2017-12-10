#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addcarform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::callNewCarWindow(void)
{
    QWidget * addCarWindow = new AddCarForm(this);
    addCarWindow->show();
}
