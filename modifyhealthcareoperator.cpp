#include "modifyhealthcareoperator.h"
#include "ui_modifyhealthcareoperator.h"
#include "typeDAO.h"
#include "ressourceDAO.h"
#include "compteDAO.h"

ModifyHealthcareOperator::ModifyHealthcareOperator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyHealthcareOperator)
{
    ui->setupUi(this);
    this->ui->loginLabel->hide();
    this->ui->loginLineEdit->hide();
    this->ui->passwordLabel->hide();
    this->ui->passwordLineEdit->hide();
}

ModifyHealthcareOperator::~ModifyHealthcareOperator()
{
    delete ui;
}

void ModifyHealthcareOperator::setRessource(Ressource* ressource){
    this->ressource = ressource;
    TypeDAO * typeDAO = new TypeDAO();
    this->ui->nameLineEdit->setText(ressource->getName());
    this->ui->firstNameLineEdit->setText(ressource->getFirstName());
    this->ui->typeBox->setCurrentText(typeDAO->getTypeById(ressource->getIdType())->getLabel());
    if(this->ui->typeBox->currentText() == "Informaticien"){
        CompteDAO * compteDAO = new CompteDAO();
        if(compteDAO->getCompteByIdRessource(ressource->getId()) != NULL){
            Compte* compte = compteDAO->getCompteByIdRessource(ressource->getId());
            this->ui->loginLineEdit->setText(compte->getLogin());
            this->ui->passwordLineEdit->setText(compte->getMdp());
        }
    }
}

void ModifyHealthcareOperator::on_modifyButton_clicked()
{
    if(this->ui->typeBox->currentText() == "Informaticien"){
        TypeDAO * typeDAO = new TypeDAO();
        RessourceDAO * ressourceDAO = new RessourceDAO();
        CompteDAO * compteDAO = new CompteDAO();
        int idType = typeDAO->getTypeIdByName(this->ui->typeBox->currentText());
        ressourceDAO->modifyRessource(ressource->getId(), this->ui->nameLineEdit->text(), this->ui->firstNameLineEdit->text(), idType);
        if(compteDAO->getCompteByIdRessource(ressource->getId()) == NULL){
            compteDAO->addCompte(compteDAO->getMaxCompteId()+1, ressource->getId(), this->ui->loginLineEdit->text(), this->ui->passwordLineEdit->text());
        }
        else {
            Compte* compte = compteDAO->getCompteByIdRessource(ressource->getId());
            compteDAO->modifyCompte(compte->getId(),ressource->getId(),this->ui->loginLineEdit->text(), this->ui->passwordLineEdit->text());
        }

        accept();
    }else{
        TypeDAO * typeDAO = new TypeDAO();
        RessourceDAO * ressourceDAO = new RessourceDAO();
        int idType = typeDAO->getTypeIdByName(this->ui->typeBox->currentText());
        ressourceDAO->modifyRessource(ressource->getId(), this->ui->nameLineEdit->text(), this->ui->firstNameLineEdit->text(), idType);
        accept();
    }
}

void ModifyHealthcareOperator::on_cancelButton_clicked()
{
    reject();
}

void ModifyHealthcareOperator::on_typeBox_currentTextChanged(const QString &arg1)
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
