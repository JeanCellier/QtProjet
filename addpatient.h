#ifndef ADDPATIENT_H
#define ADDPATIENT_H

#include <QDialog>
#include "ressourceDAO.h"

using namespace std;

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

    void on_addRessourceButton_clicked();

private:
    Ui::addPatient *ui;
    vector<Ressource *> ressources;
};

#endif // ADDPATIENT_H
