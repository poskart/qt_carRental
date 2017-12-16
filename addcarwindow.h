#ifndef ADDCARWINDOW_H
#define ADDCARWINDOW_H

#include <QMainWindow>

namespace Ui {
class AddCarWindow;
}

class AddCarWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddCarWindow(QWidget *parent = 0);
    ~AddCarWindow();

private:
    Ui::AddCarWindow *ui;
};

#endif // ADDCARWINDOW_H
