#ifndef ADDPATIENT_H
#define ADDPATIENT_H

#include <QDialog>
#include "ressourceDAO.h"
#include "patientDAO.h"
#include "consultdao.h"

/**
 * Class allowing the creation of the addpatient window
 * This window allows the user to create a patient in the database
 */

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

    /**
     * @brief updateRessourceTableView
     * Method refreshing the TableView widget of the window
     */
    void updateRessourceTableView();

private slots:

    /**
     * @brief on_createPatientButton_clicked
     * Event method when the create button is clicked
     */
    void on_createPatientButton_clicked();

    /**
     * @brief on_cancelButton_clicked
     * Event method when the cancel button is clicked
     */
    void on_cancelButton_clicked();

    /**
     * @brief on_calendar_selectionChanged
     * Event method when the selected date of the calendar changes
     */
    void on_calendar_selectionChanged();

    /**
     * @brief on_addRessourceButton_clicked
     * Event method when the add ressource button is clicked
     */
    void on_addRessourceButton_clicked();

    /**
     * @brief on_deleteRessourceButton_clicked
     * Event method when the delete ressource button is clicked
     */
    void on_deleteRessourceButton_clicked();

private:
    Ui::addPatient *ui;
    vector<Ressource *> ressources;
};

#endif // ADDPATIENT_H
