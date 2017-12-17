#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addcarwindow.h"
#include "addrentwindow.h"
#include "QAction"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    _data = new Database();

    ui->setupUi(this);
    makeConnections();

    rentingsModel = new RentingsModel(_data);
    ui->tableView->setModel(rentingsModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::debugSlot(void)
{
    qDebug("debug slot called");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeConnections(void)
{
    //connect(_data, SIGNAL(rentingChanged(void)), this, SLOT(debugSlot()));//this->ui->tableView, SLOT(updateEditorData()));
}

void MainWindow::on_actionAdd_new_car_triggered()
{
    QMainWindow * addCarWindow = new AddCarWindow(this);
    addCarWindow->show();
}

void MainWindow::on_actionRent_a_car_triggered()
{
    QMainWindow * addRentWindow = new AddRentWindow(_data, this);
    addRentWindow->show();
}

