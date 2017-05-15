#ifndef MODIFYPATIENT_H
#define MODIFYPATIENT_H

#include <QDialog>
#include "ressourceDAO.h"
#include "patientDAO.h"
#include "consultdao.h"

namespace Ui {
class ModifyPatient;
}

class ModifyPatient : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyPatient(QWidget *parent = 0);
    ~ModifyPatient();
    void setPatient(Patient* patient);
    Patient* getPatient();

private slots:
    void on_createPatientButton_clicked();

private:
    Ui::ModifyPatient *ui;
    vector<Ressource *> ressources;
    Patient* patient;
};

#endif // MODIFYPATIENT_H
