#include "consultDAO.h"
#include <QSqlDatabase>
#include <QVariant>
#include <QString>
#include <iostream>
#include "ressourceDAO.h"

using namespace std;

ConsultDAO::ConsultDAO()
{

}

ConsultDAO::~ConsultDAO(){

}

void ConsultDAO::addConsult(int id, int idPatient, int idRessource){
    this->q = handler.openBD();
    q.exec("INSERT INTO TConsult "
           "SELECT '" +QString::number(id)+"' AS 'Id', '"+QString::number(idPatient)+"' AS 'IdPatient', '"
            ""+QString::number(idRessource)+"' AS 'IdRessource'");
    handler.closeBD();
}

void ConsultDAO::deleteConsultById(int id){
    this->q = handler.openBD();
    q.exec("DELETE FROM TConsult "
           "WHERE ID = '" +QString::number(id)+"'");
    handler.closeBD();
}

void ConsultDAO::deleteConsultByValues(int idPatient, int idRessource){
    this->q = handler.openBD();
    q.exec("DELETE FROM TConsult "
           "WHERE IdPatient = '" +QString::number(idPatient)+"' AND IdRessource = '" +QString::number(idRessource)+"'");
    handler.closeBD();
}


Consult* ConsultDAO::getConsultById(int id){
    this->q = handler.openBD();
    QString idQString = QString::number(id);
    q.exec("SELECT IdPatient, IdRessource FROM TConsult WHERE Id = "+idQString+"");
    while (q.next()) {
            Consult * c = new Consult(id, q.value(0).toInt(), q.value(1).toInt());
            handler.closeBD();
            return c;
        }
    handler.closeBD();
    return NULL;
}

int ConsultDAO::getMaxConsultId(){
    this->q = handler.openBD();
    q.exec("SELECT max(id) FROM TConsult");
    while (q.next()) {
            int maxConsultId = q.value(0).toInt();
            handler.closeBD();
            return maxConsultId;
        }
    handler.closeBD();
    return 0;
}

int ConsultDAO::getNumberOfConsult(){
    this->q = handler.openBD();
    q.exec("SELECT count(*) FROM TConsult");
    while (q.next()) {
            int numberOfConsult = q.value(0).toInt();
            handler.closeBD();
            return numberOfConsult;
        }
    handler.closeBD();
    return 0;

}

vector<Ressource*> ConsultDAO::getRessourceByIdPatient(int idPatient){
    this->q = handler.openBD();
    RessourceDAO* ressourceDAO = new RessourceDAO();
    vector<Ressource*> vecRessource;
    vector<int> vecIdRessource;
    q.exec("SELECT IdRessource FROM TConsult WHERE IdPatient = '"+QString::number(idPatient)+"'");
    while (q.next()) {
            int idRessource = q.value(0).toInt();
            vecIdRessource.push_back(idRessource);
        }
    for(unsigned int numRessource = 0; numRessource < vecIdRessource.size(); numRessource++){
            Ressource* r = ressourceDAO->getRessourceById(vecIdRessource[numRessource]);
            vecRessource.push_back(r);
        }
    handler.closeBD();
    return vecRessource;
}

