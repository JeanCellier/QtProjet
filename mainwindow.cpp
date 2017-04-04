#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addpatient.h"
#include "addhealthcareoperator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPatient_triggered(bool checked)
{
}

void MainWindow::on_actionPatient_triggered()
{
    addPatient addingPatient;
    if(addingPatient.exec()==QDialog::Accepted)
    {
        addingPatient.reject();
    }
}

void MainWindow::on_actionPersonnels_de_soins_triggered()
{
    addHealthcareOperator addingHealthcareOperator;
    addingHealthcareOperator.exec();
}
