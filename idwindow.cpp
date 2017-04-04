#include "idwindow.h"
#include "ui_idwindow.h"
#include <QMessageBox>

IdWindow::IdWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IdWindow)
{
    ui->setupUi(this);
}

IdWindow::~IdWindow()
{
    delete ui;
}

void IdWindow::on_pushButton_clicked()
{

}

void IdWindow::on_pushButton_2_clicked()
{
    if(isIdValid()){
        accept();
    }else{
        int ret = QMessageBox::warning(this, "Erreur de connexion", "Login ou mot de passe incorrect");
        this->ui->lineEdit_2->setText("");
    }
}

bool IdWindow::isIdValid(){
    if(ui->lineEdit->text().size() != 0 && ui->lineEdit_2->text().size() != 0){
       return true;
    }else{
        return false;
    }
}


