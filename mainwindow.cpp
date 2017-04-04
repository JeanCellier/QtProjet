#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addpatient.h"
#include "addhealthcareoperator.h"
#include "about.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->statusBar()->showMessage("Vous venez de vous connecter");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPatient_triggered(bool checked)
{
}

void MainWindow::on_actionPatient_triggered()
{
    addPatient addingPatient;
    if(addingPatient.exec()==QDialog::Accepted)
    {
        addingPatient.reject();
    }
    this->statusBar()->showMessage("Vous venez d'ajouter un patient");
}

void MainWindow::on_actionPersonnels_de_soins_triggered()
{
    addHealthcareOperator addingHealthcareOperator;
    addingHealthcareOperator.exec();
}

void MainWindow::on_actionA_propos_triggered()
{
    about ab;
    ab.exec();
}

void MainWindow::on_actionAjouterPatient_triggered()
{
    addPatient addingPatient;
    if(addingPatient.exec()==QDialog::Accepted)
    {
        addingPatient.reject();
    }
    this->statusBar()->showMessage("Vous venez d'ajouter un patient");
}

void MainWindow::on_actionAjouterPersonnelSoins_triggered()
{
    addHealthcareOperator addingHealthcareOperator;
    addingHealthcareOperator.exec();
}
