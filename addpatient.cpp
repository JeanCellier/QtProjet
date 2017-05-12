#include "addpatient.h"
#include "ui_addpatient.h"
#include <QMessageBox>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "ressourceDAO.h"

using namespace std;

addPatient::addPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPatient)
{
    ui->setupUi(this);
    RessourceDAO* ressourceDAO = new RessourceDAO();
    for(int row = 1; row < ressourceDAO->getMaxRessourceId()+1; row++){
        Ressource* ressource = ressourceDAO->getRessourceById(row);
        if (ressource != NULL)
        ui->ressourcesComboBox->addItem(ressource->getFirstName()+" "+ressource->getName());
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
        // probleme String/QString
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
    this->ui->dayLineEdit->setText(this->ui->calendar->selectedDate().toString("yyyy-MM-dd"));
}

void addPatient::on_addRessourceButton_clicked()
{
    RessourceDAO ressourceDAO;
    QStringList list = ui->ressourcesComboBox->currentText().split(' ');
    this->ressources.push_back(ressourceDAO.getRessourceByName(list[1],list[0]));
    if (ui->ressourcesList->text() != "")
    ui->ressourcesList->setText(ui->ressourcesList->text()+", "+ui->ressourcesComboBox->currentText());
    else ui->ressourcesList->setText(ui->ressourcesComboBox->currentText());
}
