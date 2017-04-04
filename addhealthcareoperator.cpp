#include "addhealthcareoperator.h"
#include "ui_addhealthcareoperator.h"

addHealthcareOperator::addHealthcareOperator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addHealthcareOperator)
{
    ui->setupUi(this);
}

addHealthcareOperator::~addHealthcareOperator()
{
    delete ui;
}
