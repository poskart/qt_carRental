#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void makeConnections(void);
};

#endif // MAINWINDOW_H
