#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <patientDAO.h>

using namespace std;

/**
 * Class allowing the creation of the main window
 */

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /**
     * @brief on_actionPatient_triggered
     * Event method when the Patient tab is clicked
     */
    void on_actionPatient_triggered();

    /**
     * @brief on_actionPersonnels_de_soins_triggered
     * Event method when the Ressource tab is clicked
     */
    void on_actionPersonnels_de_soins_triggered();

    /**
     * @brief on_actionA_propos_triggered
     * Event method when the A propos tab is clicked
     */
    void on_actionA_propos_triggered();

    /**
     * @brief on_actionAjouterPatient_triggered
     * Event method when the add patient button is clicked
     */
    void on_actionAjouterPatient_triggered();

    /**
     * @brief on_actionAjouterPersonnelSoins_triggered
     * Event method when the add ressource button is clicked
     */
    void on_actionAjouterPersonnelSoins_triggered();

    /**
     * @brief update_patientSearchTableView
     * Method refreshing the patient table view
     */
    void update_patientSearchTableView();

    /**
     * @brief update_ressourceTreeView
     * Method refreshing the ressource table view
     */
    void update_ressourceTreeView();

    /**
     * @brief search_patientSearchTableView
     * Method filling the patient table view with the patient vector passed
     * @param vecPatient
     */
    void search_patientSearchTableView(vector<Patient*> vecPatient);

    /**
     * @brief on_toolBox_currentChanged
     * Event method when the tool box tab is changed
     * @param index
     */
    void on_toolBox_currentChanged(int index);

    /**
     * @brief on_searchButton_clicked
     * Event method when the search button is clicked
     */
    void on_searchButton_clicked();

    /**
     * @brief on_dateDebutCalendar_selectionChanged
     * Event method when the selection of the first calendar is changed
     */
    void on_dateDebutCalendar_selectionChanged();

    /**
     * @brief on_dateFinCalendar_selectionChanged
     * Event method when the selection of the second calendar is changed
     */
    void on_dateFinCalendar_selectionChanged();

    /**
     * @brief on_deleteButton_clicked
     * Event method when the delete patient button is clicked
     */
    void on_deleteButton_clicked();

    /**
     * @brief on_DeleteRessourceButton_clicked
     * Event method when the delete ressource button is clicked
     */
    void on_DeleteRessourceButton_clicked();

    /**
     * @brief on_modifierButton_clicked
     * Event method when the modify patient button is clicked
     */
    void on_modifierButton_clicked();

    /**
     * @brief on_ModifierButton_clicked
     * Event method when the modify ressource button is clicked
     */
    void on_ModifierButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
