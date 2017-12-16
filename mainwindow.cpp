#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addcarwindow.h"
#include "QAction"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    _data = new Database();

    ui->setupUi(this);
    makeConnections();

    Car newCar1 = Car("Audi", "Car", "SZA 391", 59000.00, 120 );
    Car newCar2 = Car("Skoda", "Car", "TM 402", 284992, 150);
    Car newCar3 = Car("Jelcz", "Truck", "FV 1341", 944242, 450);
    _data->addCar(newCar1);
    _data->addCar(newCar2);
    _data->addCar(newCar3);

    carsModel = new CarsModel();
    carsModel->setData(_data->getCarList());
    ui->tableView->setModel(carsModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
