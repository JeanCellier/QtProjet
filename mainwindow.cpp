#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addpatient.h"
#include "modifypatient.h"
#include "addhealthcareoperator.h"
#include "about.h"
#include "QStandardItemModel"
#include "QFileSystemModel"
#include "patientDAO.h"
#include "ressourceDAO.h"
#include "typeDAO.h"
#include "modifyhealthcareoperator.h"

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
        update_patientSearchTableView();
        this->statusBar()->showMessage("Vous venez d'ajouter un patient");
    }
}

void MainWindow::on_actionPersonnels_de_soins_triggered()
{
    addHealthcareOperator addingHealthcareOperator;
    if(addingHealthcareOperator.exec()==QDialog::Accepted)
    {
        addingHealthcareOperator.reject();
        update_ressourceTreeView();
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
        update_patientSearchTableView();
        this->statusBar()->showMessage("Vous venez d'ajouter un patient");

    }
}

void MainWindow::on_actionAjouterPersonnelSoins_triggered()
{
    addHealthcareOperator addingHealthcareOperator;
    if(addingHealthcareOperator.exec()==QDialog::Accepted)
    {
        addingHealthcareOperator.reject();
        update_ressourceTreeView();
        this->statusBar()->showMessage("Vous venez d'ajouter un personnel de soin");
    }
}

void MainWindow::update_patientSearchTableView(){
    PatientDAO * patientDAO = new PatientDAO();
    int rowShift = 1;
    QStringList listeNom;
    listeNom << "Nom" << "Prenom" << "Jour de consultation" << "Numéro d'identification";
    QStandardItemModel * standardItemModel = new QStandardItemModel(patientDAO->getNumberOfPatient(),4);
    standardItemModel->setHorizontalHeaderLabels(listeNom);
    for (int row = 1; row < patientDAO->getMaxPatientId()+1; ++row) {
        Patient * patient = patientDAO->getPatientById(row);
        if(patient != NULL){
        standardItemModel->setItem(row-rowShift, 0, new QStandardItem(patient->getName()));
        standardItemModel->setItem(row-rowShift, 1, new QStandardItem(patient->getFirstName()));
        standardItemModel->setItem(row-rowShift, 2, new QStandardItem(patient->getConsultDate().toString()));
        standardItemModel->setItem(row-rowShift, 3, new QStandardItem(QString::number(patient->getId())));
        }
        else rowShift += 1;
    }

    this->ui->patientSearchTableView->setModel(standardItemModel);
}

void MainWindow::update_ressourceTreeView()
{
    QStandardItemModel * standardModel = new QStandardItemModel();
        QStandardItem *rootNode = standardModel->invisibleRootItem();
        TypeDAO * typeDAO = new TypeDAO();
        RessourceDAO * ressourceDAO = new RessourceDAO();
        for(int parent = 1; parent < typeDAO->getMaxTypeId()+1; ++parent)
        //defining a couple of items
        {
            Type* type = typeDAO->getTypeById(parent);
            if(type != NULL){
                QStandardItem *standardParent = new QStandardItem(type->getLabel());
                rootNode-> appendRow(standardParent);
                vector<Ressource*> ressources = ressourceDAO->getRessourcesByIdType(parent);
                for (unsigned int row = 0; row < ressources.size(); row++) {
                        Ressource * ressource = ressources[row];
                        QStandardItem *standardRessource = new QStandardItem(ressource->getFirstName()+" "+ressource->getName());
                        standardParent-> appendRow(standardRessource);
                }
            }
        }
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

void MainWindow::search_patientSearchTableView(vector<Patient*> vecPatient)
{
    QStringList listeNom;
    listeNom << "Nom" << "Prenom" << "Jour de consultation" << "Numéro d'identification";
    QStandardItemModel * standardItemModel = new QStandardItemModel(vecPatient.size(),4);
    standardItemModel->setHorizontalHeaderLabels(listeNom);
    for (unsigned int row = 0; row < vecPatient.size(); ++row) {
        Patient * patient = vecPatient[row];
        if(patient != NULL){
        standardItemModel->setItem(row, 0, new QStandardItem(patient->getName()));
        standardItemModel->setItem(row, 1, new QStandardItem(patient->getFirstName()));
        standardItemModel->setItem(row, 2, new QStandardItem(patient->getConsultDate().toString()));
        standardItemModel->setItem(row, 3, new QStandardItem(QString::number(patient->getId())));
        }
    }
    this->ui->patientSearchTableView->setModel(standardItemModel);
}

void MainWindow::on_searchButton_clicked()
{
    PatientDAO* patientDAO = new PatientDAO();
    vector<Patient*> vecPatient = patientDAO->getPatientsByValues(this->ui->lineEdit->text().toInt(),
                                    this->ui->nameSearchLineEdit->text(),this->ui->prenomSearchLineEdit->text(),
                                    this->ui->dateDebutLineEdit->text(),this->ui->endDateLineEdit->text());

    search_patientSearchTableView(vecPatient);
}


void MainWindow::on_dateDebutCalendar_selectionChanged()
{
    this->ui->dateDebutLineEdit->setText(this->ui->dateDebutCalendar->selectedDate().toString("yyyy-MM-dd"));
}

void MainWindow::on_dateFinCalendar_selectionChanged()
{
    this->ui->endDateLineEdit->setText(this->ui->dateFinCalendar->selectedDate().toString("yyyy-MM-dd"));
}

void MainWindow::on_deleteButton_clicked()
{
    PatientDAO* patientDAO = new PatientDAO();
    QAbstractItemModel * model = this->ui->patientSearchTableView->model();
    QItemSelectionModel * select = this->ui->patientSearchTableView->selectionModel();

    if(!select->selectedRows().isEmpty()){
        QModelIndex obj = select->selectedRows().at(0);

        QModelIndex nomIdx = model->index(obj.row(),0);
        QModelIndex prenomIdx = model->index(obj.row(),1);

        QString name = model->data(nomIdx).toString();
        QString firstName = model->data(prenomIdx).toString();

        patientDAO->deletePatientByName(name,firstName);
        vector<Patient*> vecPatient = patientDAO->getAllPatients();
        search_patientSearchTableView(vecPatient);
    }
}

void MainWindow::on_DeleteRessourceButton_clicked()
{
    RessourceDAO * ressourceDAO = new RessourceDAO();


    QModelIndex index = this->ui->ressourceTreeView->currentIndex();
    QVariant data = this->ui->ressourceTreeView->model()->data(index);
    QString text = data.toString();

    map<int, QString> names = ressourceDAO->getRessourcesFullNames();
    map<int, QString>::const_iterator mit;

    for(mit = names.begin();mit!=names.end();mit++) {
        if(text == mit->second){
            ressourceDAO->deleteRessourceById(mit->first);
        }
      }

    update_ressourceTreeView();
}

void MainWindow::on_modifierButton_clicked()
{
    PatientDAO* patientDAO = new PatientDAO();
    QAbstractItemModel * model = this->ui->patientSearchTableView->model();
    QItemSelectionModel * select = this->ui->patientSearchTableView->selectionModel();

    if(!select->selectedRows().isEmpty()){
        QModelIndex obj = select->selectedRows().at(0);

        QModelIndex nomIdx = model->index(obj.row(),0);
        QModelIndex prenomIdx = model->index(obj.row(),1);

        QString name = model->data(nomIdx).toString();
        QString firstName = model->data(prenomIdx).toString();

        Patient * patient = patientDAO->getPatientByName(name,firstName);

        ModifyPatient modifyPatient;
        modifyPatient.setPatient(patient);
        if(modifyPatient.exec()==QDialog::Accepted)
        {
            modifyPatient.reject();
            update_ressourceTreeView();
            this->statusBar()->showMessage("Vous venez de modifier un patient");
        }
    }
}

void MainWindow::on_ModifierButton_clicked()
{
    RessourceDAO * ressourceDAO = new RessourceDAO();
    Ressource * ressource = NULL;

    QModelIndex index = this->ui->ressourceTreeView->currentIndex();
    QVariant data = this->ui->ressourceTreeView->model()->data(index);
    QString text = data.toString();

    map<int, QString> names = ressourceDAO->getRessourcesFullNames();
    map<int, QString>::const_iterator mit;

    for(mit = names.begin();mit!=names.end();mit++) {
        if(text == mit->second){
            ressource = ressourceDAO->getRessourceById(mit->first);
        }
      }
    if (ressource != NULL){
        ModifyHealthcareOperator modifyHealthcareOperator;
        modifyHealthcareOperator.setRessource(ressource);
        if(modifyHealthcareOperator.exec()==QDialog::Accepted)
        {
            modifyHealthcareOperator.reject();
            update_ressourceTreeView();
            this->statusBar()->showMessage("Vous venez de modifier une ressource");
        }
    }
}
