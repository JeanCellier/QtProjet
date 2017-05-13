#include "PatientDAO.h"
#include <QSqlDatabase>
#include <QVariant>
#include <QString>
#include <iostream>

using namespace std;

PatientDAO::PatientDAO()
{
}

PatientDAO::~PatientDAO()
{
}

void PatientDAO::addPatient(int id, QString name, QString firstName, QString address, QString city, QString zipCode, QString comment, int phoneNumber, QDate consultDate, int consultTime, int priority){
    this->q = handler.openBD();
    if (comment == NULL) comment = "";
    q.exec("INSERT INTO TPatient "
           "SELECT '" +QString::number(id)+"' AS 'Id', '"+name+"' AS 'Nom', '"+firstName+"' AS 'Prenom', '"+address+"' AS 'Adresse', '"+city+"' AS 'Ville', '"+zipCode+"' AS 'CP'"
           ", '"+comment+"' AS 'Commentaire', '"+QString::number(phoneNumber)+"' AS 'Tel', '"+consultDate.toString("yyyy-MM-dd")+"' AS 'DateConsultation', '"+QString::number(consultTime)+"' AS 'DureeConsultation', '"+QString::number(priority)+"' AS 'Priorite'");
    handler.closeBD();
}

vector<Patient*> PatientDAO::getPatientsByValues(int id, QString name, QString firstName, QString startConsultDate, QString endConsultDate){
    this->q = handler.openBD();
    vector<Patient*> vecPatient;
    QString sqlCommand = "SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateConsultation, DureeConsultation, Priorite FROM TPatient WHERE Nom LIKE '"+name+"%' AND Prenom LIKE '"+firstName+"%'";
    if (id != 0) sqlCommand += " AND Id = '"+QString::number(id)+"'";
    if (startConsultDate != "") sqlCommand += " AND DateConsultation >= '"+startConsultDate+"'";
    if (endConsultDate != "") sqlCommand += " AND DateConsultation <= '"+endConsultDate+"'";

    q.exec(sqlCommand);
    while (q.next()) {
            Patient * p = new Patient(q.value(0).toInt(), q.value(1).toString(), q.value(2).toString(),
                                    q.value(3).toString(), q.value(4).toString(), q.value(5).toString(),
                                    q.value(6).toString(), q.value(7).toInt(), q.value(8).toDate(),
                                    q.value(9).toInt(),q.value(10).toInt());
            vecPatient.push_back(p);
        }
    handler.closeBD();
    return vecPatient;
}

vector<Patient*> PatientDAO::getAllPatients(){
    this->q = handler.openBD();
    vector<Patient*> vecPatient;
    QString sqlCommand = "SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateConsultation, DureeConsultation, Priorite FROM TPatient";

    q.exec(sqlCommand);
    while (q.next()) {
            Patient * p = new Patient(q.value(0).toInt(), q.value(1).toString(), q.value(2).toString(),
                                    q.value(3).toString(), q.value(4).toString(), q.value(5).toString(),
                                    q.value(6).toString(), q.value(7).toInt(), q.value(8).toDate(),
                                    q.value(9).toInt(),q.value(10).toInt());
            vecPatient.push_back(p);
        }
    handler.closeBD();
    return vecPatient;
}

Patient* PatientDAO::getPatientById(int id){
    this->q = handler.openBD();
    QString idQString = QString::number(id);
    q.exec("SELECT Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateConsultation, DureeConsultation, Priorite FROM TPatient WHERE Id = "+idQString+"");
    while (q.next()) {
            Patient * p = new Patient(id, q.value(0).toString(), q.value(1).toString(), q.value(2).toString(),
                                    q.value(3).toString(), q.value(4).toString(), q.value(5).toString(),
                                    q.value(6).toInt(), q.value(7).toDate(), q.value(8).toInt(),
                                    q.value(9).toInt());
            handler.closeBD();
            return p;
        }
    handler.closeBD();
    return NULL;
}

int PatientDAO::getNumberOfPatient(){
    this->q = handler.openBD();
    q.exec("SELECT count(*) FROM TPatient");
    while (q.next()) {
            int numberOfPatient = q.value(0).toInt();
            handler.closeBD();
            return numberOfPatient;
        }
    handler.closeBD();
    return 0;
}

int PatientDAO::getMaxPatientId(){
    this->q = handler.openBD();
    q.exec("SELECT max(id) FROM TPatient");
    while (q.next()) {
            int maxPatientId = q.value(0).toInt();
            handler.closeBD();
            return maxPatientId;
        }
    handler.closeBD();
    return 0;
}

void PatientDAO::deletePatientById(int id){
    this->q = handler.openBD();
    q.exec("DELETE FROM TPatient WHERE Id = "+QString::number(id));
    handler.closeBD();
}

Patient* PatientDAO::getPatientByName(QString nom, QString prenom){
    this->q = handler.openBD();
    //QString idQString = QString::number(id);
    q.exec("SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateConsultation, DureeConsultation, Priorite FROM TPatient WHERE Nom = '"+nom+"' AND Prenom = '"+prenom+"'");
    while (q.next()) {
            Patient * p = new Patient(q.value(0).toInt(), q.value(1).toString(), q.value(2).toString(), q.value(3).toString(),
                                    q.value(4).toString(), q.value(5).toString(), q.value(6).toString(),
                                    q.value(7).toInt(), q.value(8).toDate(), q.value(9).toInt(),
                                    q.value(10).toInt());
            handler.closeBD();
            return p;
        }
    handler.closeBD();
    return NULL;
}


void PatientDAO::deletePatientByName(QString name, QString firstName){
    this->q = handler.openBD();
    q.exec("DELETE FROM TPatient WHERE Nom = '"+name+"' AND Prenom = '"+firstName+"'");
    handler.closeBD();
}
