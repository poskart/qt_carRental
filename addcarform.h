#ifndef ADDCARFORM_H
#define ADDCARFORM_H

#include <QWidget>

namespace Ui {
class AddCarForm;
}

class AddCarForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddCarForm(QWidget *parent = 0);
    ~AddCarForm();

private:
    Ui::AddCarForm *ui;
};

#endif // ADDCARFORM_H
