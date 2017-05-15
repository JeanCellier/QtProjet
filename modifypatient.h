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
    void updateRessourceTableView();

private slots:
    void on_modifyPatientButton_clicked();

    void on_deleteRessourceButton_clicked();

    void on_calendar_selectionChanged();

    void on_cancelButton_clicked();

    void on_addRessourceButton_clicked();

private:
    Ui::ModifyPatient *ui;
    vector<Ressource *> ressources;
    Patient* patient;
};

#endif // MODIFYPATIENT_H
