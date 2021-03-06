#include "addhealthcareoperator.h"
#include "ui_addhealthcareoperator.h"
#include "typeDAO.h"
#include "ressourceDAO.h"
#include "compteDAO.h"

addHealthcareOperator::addHealthcareOperator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addHealthcareOperator)
{
    ui->setupUi(this);
    this->ui->loginLabel->hide();
    this->ui->loginLineEdit->hide();
    this->ui->passwordLabel->hide();
    this->ui->passwordLineEdit->hide();
}

addHealthcareOperator::~addHealthcareOperator()
{
    delete ui;
}

void addHealthcareOperator::on_typeBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Informaticien"){
        this->ui->loginLabel->show();
        this->ui->loginLineEdit->show();
        this->ui->passwordLabel->show();
        this->ui->passwordLineEdit->show();
    }else{
        if(this->ui->passwordLabel->isVisible()){
            this->ui->loginLabel->hide();
            this->ui->loginLineEdit->hide();
            this->ui->passwordLabel->hide();
            this->ui->passwordLineEdit->hide();
        }
    }
}

void addHealthcareOperator::on_cancelButton_clicked()
{
    reject();
}

void addHealthcareOperator::on_addButton_clicked()
{
    if(this->ui->typeBox->currentText() == "Informaticien"){
        TypeDAO * typeDAO = new TypeDAO();
        RessourceDAO * ressourceDAO = new RessourceDAO();
        CompteDAO * compteDAO = new CompteDAO();
        int idType = typeDAO->getTypeIdByName(this->ui->typeBox->currentText());
        int idRessourceInseree = ressourceDAO->getMaxRessourceId()+1;
        ressourceDAO->addRessource(ressourceDAO->getMaxRessourceId()+1, this->ui->nameLineEdit->text(), this->ui->firstNameLineEdit->text(), idType);
        compteDAO->addCompte(compteDAO->getMaxCompteId()+1, idRessourceInseree, this->ui->loginLineEdit->text(), this->ui->passwordLineEdit->text());
        accept();
    }else{
        TypeDAO * typeDAO = new TypeDAO();
        RessourceDAO * ressourceDAO = new RessourceDAO();
        int idType = typeDAO->getTypeIdByName(this->ui->typeBox->currentText());
        ressourceDAO->addRessource(ressourceDAO->getMaxRessourceId()+1, this->ui->nameLineEdit->text(), this->ui->firstNameLineEdit->text(), idType);
        accept();
    }
}
