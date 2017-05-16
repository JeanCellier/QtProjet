#ifndef MODIFYPATIENT_H
#define MODIFYPATIENT_H

#include <QDialog>
#include "ressourceDAO.h"
#include "patientDAO.h"
#include "consultdao.h"

/**
 * Class allowing the creation of the modifypatient window
 * This window allows the user to create a ressource in the database
 */

namespace Ui {
class ModifyPatient;
}

class ModifyPatient : public QDialog
{
        Q_OBJECT

    public:
        explicit ModifyPatient(QWidget *parent = 0);
        ~ModifyPatient();

        /**
         * @brief setPatient
         * Sets the fields of the window with the previously selected patient
         * @param patient
         */
        void setPatient(Patient* patient);

        /**
         * @brief getPatient
         * Gets the entered patient
         * @return
         */
        Patient* getPatient();

        /**
         * @brief updateRessourceTableView
         * Updates the ressource table view of the patient
         */
        void updateRessourceTableView();

    private slots:

        /**
         * @brief on_modifyPatientButton_clicked
         * Event method when the modify button is clicked
         */
        void on_modifyPatientButton_clicked();

        /**
         * @brief on_deleteRessourceButton_clicked
         * Event method when the delete ressource button is clicked
         */
        void on_deleteRessourceButton_clicked();

        /**
         * @brief on_calendar_selectionChanged
         * Event method when the calendar selection changes
         */
        void on_calendar_selectionChanged();

        /**
         * @brief on_cancelButton_clicked
         * Event method when the cancel button is clicked
         */
        void on_cancelButton_clicked();

        /**
         * @brief on_addRessourceButton_clicked
         * Event when the add ressource button is clicked
         */
        void on_addRessourceButton_clicked();

    private:
        Ui::ModifyPatient *ui;
        vector<Ressource *> ressources;
        Patient* patient;
};

#endif // MODIFYPATIENT_H
