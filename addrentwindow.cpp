#include "addrentwindow.h"
#include "ui_addrentwindow.h"

#include <QMessageBox>
#include "mainwindow.h"

AddRentWindow::AddRentWindow(Database * db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddRentWindow), _data(db)
{
    ui->setupUi(this);
    carsModel = new CarsModel();
    peopleModel = new PeopleModel();
    carsModel->setData(_data->getCarList());
    peopleModel->setData(_data->getPeopleList());
    ui->carsTableView->setModel(carsModel);
    ui->personTableView->setModel(peopleModel);
    ui->carsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->personTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->beginDateEdit->setDate(QDate::currentDate());
    ui->endDateEdit->setDate(QDate::currentDate().addDays(7));
}

AddRentWindow::~AddRentWindow()
{
    delete ui;
}

void AddRentWindow::on_addRentButton_clicked()
{
    QItemSelectionModel *personSelect = ui->personTableView->selectionModel();
    QItemSelectionModel *carSelect = ui->carsTableView->selectionModel();

    if(carSelect->hasSelection() && personSelect->hasSelection() &&
            carSelect->selectedIndexes().size() == 1 && personSelect->selectedIndexes().size() == 1)
    {
        QModelIndex carIdIdx = carSelect->selectedIndexes().at(0).sibling(
                    carSelect->selectedIndexes().at(0).row(), 1);
        QModelIndex personIdIdx = personSelect->selectedIndexes().at(0).sibling(
                    personSelect->selectedIndexes().at(0).row(), 2);

        if(carIdIdx.isValid() && personIdIdx.isValid())
        {
            Person * p = _data->findPerson(
                        ui->personTableView->model()->data(personIdIdx, Qt::DisplayRole).toString());
            Car * c = _data->findCar(
                        ui->carsTableView->model()->data(carIdIdx, Qt::DisplayRole).toString());
            Renting r = Renting(p, c, ui->beginDateEdit->date(), ui->endDateEdit->date());
            _data->addRenting(r);
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("You must select exactly one row from each table!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
    this->close();
}

void AddRentWindow::on_cancelButton_clicked()
{
    this->close();
}
