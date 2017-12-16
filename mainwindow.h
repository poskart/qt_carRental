#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "person.h"
#include "car.h"
#include "renting.h"
#include "carsModel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

private slots:
    void on_actionAdd_new_car_triggered();

private:
    Ui::MainWindow *ui;

    CarsModel * carsModel;

    std::vector<Car> cars;
    std::vector<Person> people;
    std::vector<Renting> rentList;

    void makeConnections(void);
};

#endif // MAINWINDOW_H
