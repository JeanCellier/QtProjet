#include "addhealthcareoperator.h"
#include "ui_addhealthcareoperator.h"

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
