#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addcarwindow.h"
#include "addrentwindow.h"
#include "addpersonwindow.h"
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
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(recordSelected()));

}

void MainWindow::on_actionAdd_new_car_triggered()
{
    QMainWindow * addCarWindow = new AddCarWindow(_data, this);
    addCarWindow->show();
}

void MainWindow::on_actionRent_a_car_triggered()
{
    QMainWindow * addRentWindow = new AddRentWindow(_data, this);
    addRentWindow->show();
}


void MainWindow::on_actionAdd_client_triggered()
{
    QMainWindow * addClientWindow = new AddPersonWindow(_data, this);
    addClientWindow->show();
}

void MainWindow::recordSelected()
{
    QModelIndex index = ui->tableView->currentIndex();
    QModelIndex carIdIdx = index.sibling(index.row(), 0);
    Renting * renting = _data->findRenting(ui->tableView->model()->data(carIdIdx, Qt::DisplayRole).toString());
    setRentingDetails(*renting);
    setCarDetails(renting->getCar());
    setClientDetails(renting->getPerson());
}

void MainWindow::setRentingDetails(Renting & r)
{
    ui->rentBeginDateLabel->setText(r.getBeginDate().toString());
    ui->rentEndDateLabel->setText(r.getEndDate().toString());
    ui->clientIdNumberLabel1->setText(r.getPerson().getIdNumber());
    ui->carIdNumberLabel1->setText(r.getCar().getIdNumber());
}

void MainWindow::setCarDetails(Car & c)
{
    ui->carNameLabel->setText(c.getName());
    ui->carIdNumberLabel2->setText(c.getIdNumber());
    ui->carTypeLabel->setText(c.getType());
    ui->carPriceLabel->setText(QString::number(c.getPrice()));
    ui->carTypeLabel->setText(QString::number(c.getPower()));
}

void MainWindow::setClientDetails(Person & p)
{
    ui->clientNameLabel->setText(p.getName());
    ui->clientSurnameLabel->setText(p.getSecName());
    ui->clientIdNumberLabel2->setText(p.getIdNumber());
    ui->clientAgeLabel->setText(QString::number(p.getAge()));
}
