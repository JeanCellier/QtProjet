#include "RessourceDAO.h"
#include <iostream>

using namespace std;

RessourceDAO::RessourceDAO()
{
}

RessourceDAO::~RessourceDAO()
{
}

void RessourceDAO::addRessource(int id, QString name, QString firstName, int idType){
    this->q = handler.openBD();
    q.exec("INSERT INTO TRessource "
           "SELECT '"+QString::number(id)+"' AS 'Id', '"+name+"' AS 'Nom', '"+firstName+"' "
           "AS 'Prenom', '"+QString::number(idType)+"' AS 'IdType'");
    handler.closeBD();
}

Ressource* RessourceDAO::getRessourceById(int id){
    this->q = handler.openBD();
    q.exec("SELECT Nom, Prenom, IdType FROM TRessource WHERE Id = "+QString::number(id)+"");
    while (q.next()) {
            Ressource* r = new Ressource(id, q.value(0).toString(), q.value(1).toString(), q.value(2).toInt());
            handler.closeBD();
            return r;
        }
    handler.closeBD();
    return NULL;
}

Ressource* RessourceDAO::getRessourceByName(QString name, QString firstName){
    this->q = handler.openBD();
    q.exec("SELECT Id, IdType FROM TRessource WHERE Nom = '"+name+"' AND Prenom = '"+firstName+"'");
    while (q.next()) {
            Ressource* r = new Ressource(q.value(0).toInt(), name, firstName, q.value(1).toInt());
            handler.closeBD();
            return r;
        }
    handler.closeBD();
    return NULL;
}

vector<Ressource*> RessourceDAO::getRessourcesByIdType(int idType){
    this->q = handler.openBD();
    vector<Ressource*> vecRessource;
    q.exec("SELECT Id, Nom, Prenom FROM TRessource WHERE IdType = "+QString::number(idType)+"");
    while (q.next()) {
            Ressource* r = new Ressource(q.value(0).toInt(), q.value(1).toString(), q.value(2).toString(), idType);
            vecRessource.push_back(r);
        }
    handler.closeBD();
    return vecRessource;
}

int RessourceDAO::getNumberOfRessourceByIdType(int idType){
    this->q = handler.openBD();
    q.exec("SELECT count(*) FROM TRessource WHERE IdType = "+QString::number(idType)+"");
    while (q.next()) {
            int numberOfRessource = q.value(0).toInt();
            handler.closeBD();
            return numberOfRessource;
        }
    handler.closeBD();
    return 0;
}

int RessourceDAO::getNumberOfRessource(){
    this->q = handler.openBD();
    q.exec("SELECT count(*) FROM TRessource");
    while (q.next()) {
            int numberOfRessource = q.value(0).toInt();
            handler.closeBD();
            return numberOfRessource;
        }
    handler.closeBD();
    return 0;
}

int RessourceDAO::getMaxRessourceId(){
    this->q = handler.openBD();
    q.exec("SELECT max(id) FROM TRessource");
    while (q.next()) {
            int maxRessourceId = q.value(0).toInt();
            handler.closeBD();
            return maxRessourceId;
        }
    handler.closeBD();
    return 0;
}

map<int, QString> RessourceDAO::getRessourcesFullNames(){
    this->q = handler.openBD();
    map<int, QString> names;
    q.exec("SELECT Id, Nom, Prenom FROM TRessource");
    while (q.next()) {
            names[q.value(0).toInt()] = q.value(2).toString() + " " + q.value(1).toString();
        }
    handler.closeBD();
    return names;
}

void RessourceDAO::deleteRessourceById(int id){
    this->q = handler.openBD();
    q.exec("DELETE FROM TRessource WHERE Id = "+QString::number(id));
    handler.closeBD();
}
