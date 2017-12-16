#ifndef ADDRENTWINDOW_H
#define ADDRENTWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "carsModel.h"
#include "peoplemodel.h"

namespace Ui {
class AddRentWindow;
}

class AddRentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddRentWindow(Database * db, QWidget *parent = 0);
    ~AddRentWindow();

private slots:
    void on_addRentButton_clicked();

    void on_cancelButton_clicked();

    private:
    Ui::AddRentWindow *ui;
    Database * _data;
    CarsModel * carsModel;
    PeopleModel * peopleModel;
};

#endif // ADDRENTWINDOW_H
