#include "addrentwindow.h"
#include "ui_addrentwindow.h"

#include <QMessageBox>

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

    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("You must select exactly one row from each table!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
    //    select->hasSelection();
    //    select->selectedRows();
    //    select->selectedColumns();
}

void AddRentWindow::on_cancelButton_clicked()
{
    this->close();
}
