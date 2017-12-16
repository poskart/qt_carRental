#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addcarwindow.h"
#include "QAction"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        ui->setupUi(this);

        Car newCar1 = Car("Audi", "Car", "SZA 391", 59000.00, 120 );
        Car newCar2 = Car("Skoda", "Car", "TM 402", 284992, 150);
        Car newCar3 = Car("Jelcz", "Truck", "FV 1341", 1244242, 450);
        cars.push_back(newCar1);
        cars.push_back(newCar2);
        cars.push_back(newCar3);

        carsModel = new CarsModel();
        carsModel->setData(&cars);
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
