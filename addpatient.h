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

private slots:
    void on_createPatientButton_clicked();

    void on_cancelButton_clicked();

    void on_calendar_selectionChanged();

private:
    Ui::addPatient *ui;
};

#endif // ADDPATIENT_H
