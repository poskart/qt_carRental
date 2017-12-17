#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "rentingsmodel.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

public slots:
    void debugSlot(void);

private slots:
    void on_actionAdd_new_car_triggered();
    void on_actionRent_a_car_triggered();
    void recordSelected();

    void on_actionAdd_client_triggered();

private:
    void setRentingDetails(Renting & r);
    void setCarDetails(Car & c);
    void setClientDetails(Person & p);

    Ui::MainWindow *ui;
    Database * _data;
    RentingsModel * rentingsModel;

    void makeConnections(void);
};

#endif // MAINWINDOW_H
