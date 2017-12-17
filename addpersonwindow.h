#ifndef ADDPERSONWINDOW_H
#define ADDPERSONWINDOW_H

#include <QMainWindow>
#include "database.h"

namespace Ui {
class AddPersonWindow;
}

class AddPersonWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddPersonWindow(Database * db, QWidget *parent = 0);
    ~AddPersonWindow();

private slots:
    void on_cButton_clicked();

private:
    Ui::AddPersonWindow *ui;
    Database * _data;
};

#endif // ADDPERSONWINDOW_H
