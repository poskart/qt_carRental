#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addcarwindow.h"
#include "QAction"

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

void MainWindow::makeConnections(void)
{
}

void MainWindow::on_actionAdd_new_car_triggered()
{
    QMainWindow * addCarWindow = new AddCarWindow(this);
    addCarWindow->show();
}
