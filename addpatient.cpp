#include "addpatient.h"
#include "ui_addpatient.h"
#include <QMessageBox>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "ressourceDAO.h"
#include "QStandardItemModel"

using namespace std;

addPatient::addPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPatient)
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

addPatient::~addPatient()
{
    delete ui;
}

void addPatient::on_createPatientButton_clicked()
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
    }else if(this->ressources.empty()){
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez ajouter des ressources !");
        champVide = true;
    }

    if(champVide == false){
        PatientDAO* patientDAO = new PatientDAO();
        ConsultDAO* consultDAO = new ConsultDAO();
        int newPatientId = patientDAO->getMaxPatientId()+1;
        QDate date = QDate::fromString(this->ui->dayLineEdit->text(),"yyyy-MM-dd");

        patientDAO->addPatient(newPatientId,this->ui->nameLineEdit->text(),
            this->ui->fistNameLineEdit->text(),this->ui->addressLineEdit->text(),this->ui->cityLineEdit->text(),
            this->ui->zipLineEdit->text(),this->ui->commentaryLineEdit->text(),this->ui->phoneNumberLineEdit->text(),
            date, this->ui->minutesSpinBox->text().toInt(),
            this->ui->priorityComboBox->currentText().toInt());

        for (unsigned int numRessource = 0; numRessource < ressources.size(); numRessource++){
            Ressource* ressource = ressources[numRessource];
            consultDAO->addConsult(consultDAO->getMaxConsultId()+1,newPatientId,ressource->getId());
        }

        //formater les champs majuscule/minuscule
        accept();
    }
    //accept();
}

void addPatient::on_cancelButton_clicked()
{
    reject();
}

void addPatient::on_calendar_selectionChanged()
{
    if(this->ui->calendar->selectedDate() < QDate::currentDate()){
        QMessageBox::warning(this, "Erreur de saisie", "Date antérieure à la date d'aujourd'hui !");
    }
    else this->ui->dayLineEdit->setText(this->ui->calendar->selectedDate().toString("yyyy-MM-dd"));
}

void addPatient::on_addRessourceButton_clicked()
{
    RessourceDAO ressourceDAO;
    QStringList list = ui->ressourcesComboBox->currentText().split(' ');
    bool itemExist = false;
    for (unsigned int numRessource = 0; numRessource < ressources.size(); numRessource++){
        if(ressources[numRessource]->getId() == list[0].toInt()){
            QMessageBox::warning(this, "Erreur de saisie", "Deux ressources identiques !");
            itemExist = true;
        }
    }
    if(!itemExist) this->ressources.push_back(ressourceDAO.getRessourceById(list[0].toInt()));
    updateRessourceTableView();
}

void addPatient::updateRessourceTableView()
{
    QStringList listeNom;
    listeNom << "Nom" << "Prenom";
    QStandardItemModel * standardItemModel = new QStandardItemModel(ressources.size(),2);
    standardItemModel->setHorizontalHeaderLabels(listeNom);
    for (unsigned int row = 0; row < ressources.size(); ++row) {
        Ressource * ressource = ressources[row];
        if(ressource != NULL){
        standardItemModel->setItem(row, 0, new QStandardItem(ressource->getName()));
        standardItemModel->setItem(row, 1, new QStandardItem(ressource->getFirstName()));
        }
    }
    this->ui->ressourceTableView->setModel(standardItemModel);
}

void addPatient::on_deleteRessourceButton_clicked()
{
    QItemSelectionModel * select = this->ui->ressourceTableView->selectionModel();

    if(!select->selectedRows().isEmpty()){
        QModelIndex obj = select->selectedRows().at(0);
        int id = obj.row();
        ressources.erase(ressources.begin()+id);
        updateRessourceTableView();
    }
}
