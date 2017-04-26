#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_toolBox_currentChanged(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
