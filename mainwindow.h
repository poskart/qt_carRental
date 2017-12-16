#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
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

signals:

public slots:

private slots:
    void on_actionAdd_new_car_triggered();

private:
    Ui::MainWindow *ui;

    Database * _data;
    CarsModel * carsModel;

    void makeConnections(void);
};

#endif // MAINWINDOW_H
