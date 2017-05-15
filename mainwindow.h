#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <patientDAO.h>

using namespace std;

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
    void on_actionPatient_triggered(bool checked);

    void on_actionPatient_triggered();

    void on_actionPersonnels_de_soins_triggered();

    void on_actionA_propos_triggered();

    void on_actionAjouterPatient_triggered();

    void on_actionAjouterPersonnelSoins_triggered();

    void update_patientSearchTableView();

    void update_ressourceTreeView();

    void search_patientSearchTableView(vector<Patient*> vecPatient);

    void on_toolBox_currentChanged(int index);

    void on_searchButton_clicked();

    void on_dateDebutCalendar_selectionChanged();

    void on_dateFinCalendar_selectionChanged();

    void on_deleteButton_clicked();

    void on_DeleteRessourceButton_clicked();
    void on_modifierButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
