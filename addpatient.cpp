#include "addpatient.h"
#include "ui_addpatient.h"
#include <QMessageBox>
#include <stdio.h>
#include <iostream>
#include <algorithm>

addPatient::addPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPatient)
{
    ui->setupUi(this);
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
        //formater les champs majuscule/minuscule
        // probleme String/QString
    }
    //accept();
}

void addPatient::on_cancelButton_clicked()
{
    reject();
}

void addPatient::on_calendar_selectionChanged()
{
    this->ui->dayLineEdit->setText(this->ui->calendar->selectedDate().toString());
}
