#ifndef ADDPERSONWINDOW_H
#define ADDPERSONWINDOW_H

#include <QMainWindow>

namespace Ui {
class AddPersonWindow;
}

class AddPersonWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddPersonWindow(QWidget *parent = 0);
    ~AddPersonWindow();

private:
    Ui::AddPersonWindow *ui;
};

#endif // ADDPERSONWINDOW_H
