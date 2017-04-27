#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addpatient.h"
#include "addhealthcareoperator.h"
#include "about.h"
#include "QStandardItemModel"
#include "QFileSystemModel"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->statusBar()->showMessage("Vous venez de vous connecter");

    update_patientSearchTableView();
    update_ressourceTreeView();
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

void MainWindow::update_patientSearchTableView(){
    QStringList listeNom;
    listeNom << "Nom" << "Prenom" << "Adresse" << "Ville" << "Code Postal" << "Durée de consultation"
             << "Jour de consultation" << "Priorité" << "Ressources";
    QStandardItemModel * standardItemModel = new QStandardItemModel(0,9,0);
    standardItemModel->setHorizontalHeaderLabels(listeNom);
    this->ui->patientSearchTableView->setModel(standardItemModel);
}

void MainWindow::update_ressourceTreeView()
{
    QStandardItemModel * standardModel = new QStandardItemModel();
    QStandardItem *rootNode = standardModel->invisibleRootItem();


    //defining a couple of items
    QStandardItem *doctorAItem = new QStandardItem("Docteur A");
    QStandardItem *doctorBItem = new QStandardItem("Docteur B");
    QStandardItem *radioItem = new QStandardItem("Radiologue");
    QStandardItem *nurseItem = new QStandardItem("Infirmiere");
    QStandardItem *kineItem = new QStandardItem("Kinesitherapeute");
    QStandardItem *psyItem = new QStandardItem("Psychologue");

    QStandardItem *jeanItem = new QStandardItem("Jean");
    QStandardItem *pierreItem = new QStandardItem("Pierre");

    //building up the hierarchy
    rootNode-> appendRow(doctorAItem);
    rootNode-> appendRow(doctorBItem);
    rootNode-> appendRow(radioItem);
    rootNode-> appendRow(nurseItem);
    rootNode-> appendRow(kineItem);
    rootNode-> appendRow(psyItem);

    doctorAItem -> appendRow(jeanItem);
    psyItem -> appendRow(pierreItem);

    //register the model
    this->ui->ressourceTreeView->setModel(standardModel);
    this->ui->ressourceTreeView->expandAll();
}

void MainWindow::on_toolBox_currentChanged(int index)
{
    if (index==0){
        update_patientSearchTableView();
    }
    if (index==1){
        update_ressourceTreeView();
    }
}
