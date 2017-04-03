#ifndef ADDPATIENT_H
#define ADDPATIENT_H

#include <QDialog>

namespace Ui {
class addPatient;
}

class addPatient : public QDialog
{
    Q_OBJECT

public:
    explicit addPatient(QWidget *parent = 0);
    ~addPatient();

private:
    Ui::addPatient *ui;
};

#endif // ADDPATIENT_H
