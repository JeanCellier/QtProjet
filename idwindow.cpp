#include "idwindow.h"
#include "ui_idwindow.h"
#include <QMessageBox>
#include <c_init_bd.h>
#include "compteDAO.h"

IdWindow::IdWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IdWindow)
{
    ui->setupUi(this);
    C_INIT_BD::Creation_BD();
}

IdWindow::~IdWindow()
{
    delete ui;
}

void IdWindow::on_cancelButton_clicked()
{
    reject();
}

void IdWindow::on_connectButton_clicked()
{
    if(isIdValid()){
        accept();

    }else{
        QMessageBox::warning(this, "Erreur de connexion", "Login ou mot de passe incorrect");
        this->ui->passwordLineEdit->setText("");
    }
}

bool IdWindow::isIdValid(){
    CompteDAO * compteDAO = new CompteDAO();
    if(ui->loginLineEdit->text().size() != 0 && ui->passwordLineEdit->text().size() != 0){
        Compte * compte = compteDAO->getCompteByLogin(this->ui->loginLineEdit->text());
        if(compte == NULL){
                return false;
        }else{
            if(compte->getMdp() == this->ui->passwordLineEdit->text()){
                return true;
            }else{
                return false;
            }
        }
    }else{
        return false;
    }
}


