#ifndef ADDCARWINDOW_H
#define ADDCARWINDOW_H

#include <QMainWindow>
#include "database.h"

namespace Ui {
class AddCarWindow;
}

class AddCarWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddCarWindow(Database * db, QWidget *parent = 0);
    ~AddCarWindow();

private slots:
    void on_cButton_clicked();

private:
    Ui::AddCarWindow *ui;
    Database * _data;
};

#endif // ADDCARWINDOW_H
