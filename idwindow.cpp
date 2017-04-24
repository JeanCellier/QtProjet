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

void IdWindow::on_cancelButton_clicked()
{

}

void IdWindow::on_connectButton_clicked()
{
    if(isIdValid()){
        accept();

    }else{
        int ret = QMessageBox::warning(this, "Erreur de connexion", "Login ou mot de passe incorrect");
        this->ui->passwordLineEdit->setText("");
    }
}

bool IdWindow::isIdValid(){
    if(ui->loginLineEdit->text().size() != 0 && ui->passwordLineEdit->text().size() != 0){
       return true;
    }else{
        return false;
    }
}


