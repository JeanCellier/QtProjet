#include "comptedao.h"
#include <QSqlDatabase>
#include <QVariant>
#include <QString>
#include <iostream>

using namespace std;

CompteDAO::CompteDAO()
{
}

CompteDAO::~CompteDAO()
{
}

void CompteDAO::addCompte(int id, int idRessource, QString login, QString mdp){
    this->q = handler.openBD();
    q.exec("INSERT INTO TCompte "
           "SELECT '" +QString::number(id)+"' AS 'Id', '"+QString::number(idRessource)+"' AS 'IdRessource', '"+login+"' AS 'Login', '"+mdp+"' AS 'MdP'");
    handler.closeBD();
}

void CompteDAO::modifyCompte(int id, int idRessource, QString login, QString mdp){
    this->q = handler.openBD();
    q.exec("UPDATE TCompte "
           "SET IdRessource = '"+QString::number(idRessource)+"', Login = '"+login+"', Mdp = '"+mdp+"' WHERE Id = '" +QString::number(id)+"'");
    handler.closeBD();
}

Compte * CompteDAO::getCompteById(int id){
    this->q = handler.openBD();
    QString idQString = QString::number(id);
    q.exec("SELECT IdRessource, Login, Mdp FROM TCompte WHERE Id = "+idQString+"");
    while (q.next()) {
            Compte * c = new Compte(id, q.value(0).toInt(), q.value(1).toString(), q.value(2).toString());
            handler.closeBD();
            return c;
        }
    handler.closeBD();
    return NULL;
}

int CompteDAO::getNumberOfCompte(){
    this->q = handler.openBD();
    q.exec("SELECT count(*) FROM TCompte");
    while (q.next()) {
            int numberOfCompte = q.value(0).toInt();
            handler.closeBD();
            return numberOfCompte;
        }
    handler.closeBD();
    return 0;
}

int CompteDAO::getMaxCompteId(){
    this->q = handler.openBD();
    q.exec("SELECT max(id) FROM TCompte");
    while (q.next()) {
            int maxCompteId = q.value(0).toInt();
            handler.closeBD();
            return maxCompteId;
        }
    handler.closeBD();
    return 0;
}

Compte * CompteDAO::getCompteByLogin(QString login){
    this->q = handler.openBD();
    q.exec("SELECT Id, IdRessource, Mdp FROM TCompte WHERE Login = '"+login+"'");
    while (q.next()) {
            Compte * c = new Compte(q.value(0).toInt(), q.value(1).toInt(), login, q.value(2).toString());
            handler.closeBD();
            return c;
    }
    handler.closeBD();
    return NULL;
}

Compte * CompteDAO::getCompteByIdRessource(int idRessource){
    this->q = handler.openBD();
    q.exec("SELECT Id, Login, Mdp FROM TCompte");
    while (q.next()) {
            Compte * c = new Compte(q.value(0).toInt(), idRessource, q.value(1).toString(), q.value(2).toString());
            handler.closeBD();
            return c;
    }
    handler.closeBD();
    return NULL;
}

