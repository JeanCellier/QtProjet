#include "modifypatient.h"
#include "ui_modifypatient.h"
#include <QMessageBox>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

ModifyPatient::ModifyPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyPatient)
{
    ui->setupUi(this);
    RessourceDAO* ressourceDAO = new RessourceDAO();
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
    this->ui->phoneNumberLineEdit->setText(QString::number(patient->getPhoneNumber()));
    this->ui->commentaryLineEdit->setText(patient->getComment());

    ressources.clear();
    ressources = consultDAO->getRessourceByIdPatient(patient->getId());
    for(int numRessource = 0; numRessource < ressources.size(); numRessource++){
        if (ui->ressourcesList->text() != "")
        ui->ressourcesList->setText(ui->ressourcesList->text()+", "+ressources[numRessource]->getFirstName()+" "+ressources[numRessource]->getName());
        else ui->ressourcesList->setText(ressources[numRessource]->getFirstName()+" "+ressources[numRessource]->getName());
        }

}

Patient* ModifyPatient::getPatient(){

}

ModifyPatient::~ModifyPatient()
{
    delete ui;
}

void ModifyPatient::on_createPatientButton_clicked()
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
    }else if(this->ui->ressourcesList->text().isEmpty()){
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
            this->ui->zipLineEdit->text(),this->ui->commentaryLineEdit->text(),this->ui->phoneNumberLineEdit->text().toInt(),
            date, this->ui->minutesSpinBox->text().toInt(),
            this->ui->priorityComboBox->currentText().toInt());

        for (int numRessource = 0; numRessource < ressources.size(); numRessource++){
            Ressource* ressource = ressources[numRessource];
            consultDAO->addConsult(consultDAO->getMaxConsultId()+1,newPatientId,ressource->getId());
        }

        //formater les champs majuscule/minuscule
        accept();
    }
    //accept();
}


