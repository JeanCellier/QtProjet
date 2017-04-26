#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addpatient.h"
#include "addhealthcareoperator.h"
#include "about.h"
#include "QStandardItemModel"

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
        this->statusBar()->showMessage("Vous venez d'ajouter un patient");
    }
}

void MainWindow::on_actionPersonnels_de_soins_triggered()
{
    addHealthcareOperator addingHealthcareOperator;
    if(addingHealthcareOperator.exec()==QDialog::Accepted)
    {
        addingHealthcareOperator.reject();
        this->statusBar()->showMessage("Vous venez d'ajouter un personnel de soin");
    }
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
        this->statusBar()->showMessage("Vous venez d'ajouter un patient");
    }
}

void MainWindow::on_actionAjouterPersonnelSoins_triggered()
{
    addHealthcareOperator addingHealthcareOperator;
    if(addingHealthcareOperator.exec()==QDialog::Accepted)
    {
        addingHealthcareOperator.reject();
        this->statusBar()->showMessage("Vous venez d'ajouter un personnel de soin");
    }
}



void MainWindow::on_toolBox_currentChanged(int index)
{
    if (index==0){
        QStringList listeNom;
        listeNom << "Nom" << "Prenom" << "Adresse" << "Ville" << "Code Postal" << "Durée de consultation"
                 << "Jour de consultation" << "Priorité" << "Ressources";
        QStandardItemModel * standardItemModel = new QStandardItemModel(0,9,0);
        standardItemModel->setHorizontalHeaderLabels(listeNom);
        this->ui->patientSearchTableView->setModel(standardItemModel);
        this->statusBar()->showMessage("0");
    }
    if (index==1){
        this->statusBar()->showMessage("1");
    }
}
