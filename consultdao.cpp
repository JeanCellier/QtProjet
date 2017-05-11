#include "consultDAO.h"
#include <QSqlDatabase>
#include <QVariant>
#include <QString>
#include <iostream>

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
