#include "addpatient.h"
#include "ui_addpatient.h"

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
