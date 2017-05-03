#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addpatient.h"
#include "addhealthcareoperator.h"
#include "about.h"
#include "QStandardItemModel"
#include "QFileSystemModel"
#include "patientDAO.h"

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
    PatientDAO * patientDAO = new PatientDAO();
    QStringList listeNom;
    listeNom << "Nom" << "Prenom" << "Adresse" << "Ville" << "Code Postal" << "Durée de consultation"
             << "Jour de consultation" << "Priorité";
    QStandardItemModel * standardItemModel = new QStandardItemModel(patientDAO->getNumberOfPatient(),8);
    standardItemModel->setHorizontalHeaderLabels(listeNom);
    for (int row = 1; row < patientDAO->getNumberOfPatient()+1; ++row) {
        Patient * patient = patientDAO->getPatientById(row);
        standardItemModel->setItem(row-1, 0, new QStandardItem(patient->getName()));
        standardItemModel->setItem(row-1, 1, new QStandardItem(patient->getFirstName()));
        standardItemModel->setItem(row-1, 2, new QStandardItem(patient->getAddress()));
        standardItemModel->setItem(row-1, 3, new QStandardItem(patient->getCity()));
        standardItemModel->setItem(row-1, 4, new QStandardItem(patient->getZipCode()));
        standardItemModel->setItem(row-1, 5, new QStandardItem(QString::number(patient->getConsultTime())));
        standardItemModel->setItem(row-1, 6, new QStandardItem(patient->getConsultDate().toString()));
        standardItemModel->setItem(row-1, 7, new QStandardItem(QString::number(patient->getPriority())));
    }

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
