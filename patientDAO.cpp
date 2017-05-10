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
    q.exec("INSERT INTO TPatient "
           "SELECT '" +QString::number(id)+"' AS 'Id', '"+name+"' AS 'Nom', '"+firstName+"' AS 'Prenom', '"+address+"' AS 'Adresse', '"+city+"' AS 'Ville', '"+zipCode+"' AS 'CP'"
           ", '"+comment+"' AS 'Commentaire', '"+QString::number(phoneNumber)+"' AS 'Tel', '"+consultDate.toString("yyyy.dd.MM")+"' AS 'DateConsultation', '"+QString::number(consultTime)+"' AS 'DureeConsultation', '"+QString::number(priority)+"' AS 'Priorite'");
    handler.closeBD();
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

