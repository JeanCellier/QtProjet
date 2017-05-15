#include "modifypatient.h"
#include "ui_modifypatient.h"
#include <QMessageBox>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <QStandardItemModel>

using namespace std;

ModifyPatient::ModifyPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyPatient)
{
    ui->setupUi(this);
    RessourceDAO* ressourceDAO = new RessourceDAO();
    ui->ressourcesComboBox->setMaxVisibleItems(ressourceDAO->getMaxRessourceId());
    for(int row = 1; row < ressourceDAO->getMaxRessourceId()+1; row++){
        Ressource* ressource = ressourceDAO->getRessourceById(row);
        if (ressource != NULL)
        ui->ressourcesComboBox->addItem(QString::number(ressource->getId())+" "+ressource->getFirstName()+" "+ressource->getName());
    }
}

void ModifyPatient::setPatient(Patient* patient){
    ConsultDAO* consultDAO = new ConsultDAO();
    this->patient = patient;
    this->ui->nameLineEdit->setText(patient->getName());
    this->ui->fistNameLineEdit->setText(patient->getFirstName());
    this->ui->addressLineEdit->setText(patient->getAddress());
    this->ui->cityLineEdit->setText(patient->getCity());
    this->ui->zipLineEdit->setText(patient->getZipCode());
    this->ui->dayLineEdit->setText(patient->getConsultDate().toString("yyyy-MM-dd"));
    this->ui->minutesSpinBox->setValue(patient->getConsultTime());
    this->ui->priorityComboBox->setCurrentText(QString::number(patient->getPriority()));
    this->ui->phoneNumberLineEdit->setText(patient->getPhoneNumber());
    this->ui->commentaryLineEdit->setText(patient->getComment());

    ressources.clear();
    ressources = consultDAO->getRessourceByIdPatient(patient->getId());
    updateRessourceTableView();

}

Patient* ModifyPatient::getPatient(){

}

ModifyPatient::~ModifyPatient()
{
    delete ui;
}

void ModifyPatient::on_modifyPatientButton_clicked()
{
    //si tous champs valides, on accept()

    bool champVide = false;

    //check si champs vides
    if(this->ui->nameLineEdit->text().isEmpty()){
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez renseigner un nom !");
        champVide = true;
    }else if(this->ui->fistNameLineEdit->text().isEmpty()){
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez renseigner un prénom !");
        champVide = true;
    }else if(this->ui->addressLineEdit->text().isEmpty()){
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez renseigner une adresse !");
        champVide = true;
    }else if(this->ui->cityLineEdit->text().isEmpty()){
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez renseigner une ville !");
        champVide = true;
    }else if(this->ui->zipLineEdit->text().isEmpty()){
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez renseigner un code postal !");
        champVide = true;
    }else if(ressources.empty()){
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez ajouter des ressources !");
        champVide = true;
    }

    if(champVide == false){
        PatientDAO* patientDAO = new PatientDAO();
        ConsultDAO* consultDAO = new ConsultDAO();
        QDate date = QDate::fromString(this->ui->dayLineEdit->text(),"yyyy-MM-dd");

        vector<Ressource *> oldRessources = consultDAO->getRessourceByIdPatient(patient->getId());

        for (int numRessource = 0; numRessource < ressources.size(); numRessource++){
                    Ressource* ressource = ressources[numRessource];
                    bool itemExist = false;
                    for (int numRessource = 0; numRessource < oldRessources.size(); numRessource++){
                        if(oldRessources[numRessource]->getId() == ressource->getId()){
                            oldRessources.erase(oldRessources.begin()+numRessource);
                            itemExist = true;
                        }
                    }
                    if(!itemExist)consultDAO->addConsult(consultDAO->getMaxConsultId()+1,patient->getId(),ressource->getId());
                }
        for (int numRessource = 0; numRessource < oldRessources.size(); numRessource++){
            consultDAO->deleteConsultByValues(patient->getId(),oldRessources[numRessource]->getId());
        }


        patientDAO->modifyPatient(patient->getId(),this->ui->nameLineEdit->text(),
            this->ui->fistNameLineEdit->text(),this->ui->addressLineEdit->text(),this->ui->cityLineEdit->text(),
            this->ui->zipLineEdit->text(),this->ui->commentaryLineEdit->text(),this->ui->phoneNumberLineEdit->text(),
            date, this->ui->minutesSpinBox->text().toInt(),
            this->ui->priorityComboBox->currentText().toInt());

        //formater les champs majuscule/minuscule
        accept();
    }
    //accept();
}

void ModifyPatient::updateRessourceTableView()
{
    QStringList listeNom;
    listeNom << "Nom" << "Prenom";
    QStandardItemModel * standardItemModel = new QStandardItemModel(ressources.size(),2);
    standardItemModel->setHorizontalHeaderLabels(listeNom);
    for (int row = 0; row < ressources.size(); ++row) {
        Ressource * ressource = ressources[row];
        if(ressource != NULL){
        standardItemModel->setItem(row, 0, new QStandardItem(ressource->getName()));
        standardItemModel->setItem(row, 1, new QStandardItem(ressource->getFirstName()));
        }
    }
    this->ui->ressourceTableView->setModel(standardItemModel);
}

void ModifyPatient::on_deleteRessourceButton_clicked()
{
    QAbstractItemModel * model = this->ui->ressourceTableView->model();
    QItemSelectionModel * select = this->ui->ressourceTableView->selectionModel();

    if(!select->selectedRows().isEmpty()){
        QModelIndex obj = select->selectedRows().at(0);
        int id = obj.row();
        ressources.erase(ressources.begin()+id);
        updateRessourceTableView();
    }
}

void ModifyPatient::on_calendar_selectionChanged()
{
    this->ui->dayLineEdit->setText(this->ui->calendar->selectedDate().toString("yyyy-MM-dd"));
}

void ModifyPatient::on_cancelButton_clicked()
{
    reject();
}

void ModifyPatient::on_addRessourceButton_clicked()
{
    RessourceDAO ressourceDAO;
    QStringList list = ui->ressourcesComboBox->currentText().split(' ');
    bool itemExist = false;
    for (int numRessource = 0; numRessource < ressources.size(); numRessource++){
        if(ressources[numRessource]->getId() == list[0].toInt()){
            QMessageBox::warning(this, "Erreur de saisie", "Deux ressources identiques !");
            itemExist = true;
        }
    }
    if(!itemExist) this->ressources.push_back(ressourceDAO.getRessourceById(list[0].toInt()));
    updateRessourceTableView();
}
