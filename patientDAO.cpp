#include "PatientDAO.h"
#include <QSqlDatabase>
#include <QVariant>
#include <QString>
#include "BdHandler.h"
#include <iostream>

using namespace std;

PatientDAO::PatientDAO()
{
    Bdhandler handler;
    this->q = handler.openBD();
}

PatientDAO::~PatientDAO()
{
    Bdhandler handler;
    handler.closeBD();
}

void PatientDAO::addPatient(int id, QString name, QString firstName, QString address, QString city, QString zipCode, QString comment, int phoneNumber, QDate consultDate, int consultTime, int priority){
    q.exec("INSERT INTO TPatient "
           "SELECT '1' AS 'Id', 'Ricardo' AS 'Nom', 'Jacques' AS 'Prenom', '3 rue des justices' AS 'Adresse', 'Tours' AS 'Ville', '37200' AS 'CP'"
           ", 'Dépressif' AS 'Commentaire', '247558963' AS 'Commentaire', '2013-06-01' AS 'DateConsultation', '90' AS 'DureeConsultation', '2' AS 'Priorite'");
}

Patient* PatientDAO::getPatientById(int id){
    QString idQString = QString::number(id);
    q.exec("SELECT Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateConsultation, DureeConsultation, Priorite FROM TPatient WHERE Id = "+idQString+"");
    while (q.next()) {
            Patient * p = new Patient(id, q.value(0).toString(), q.value(1).toString(), q.value(2).toString(),
                                    q.value(3).toString(), q.value(4).toString(), q.value(5).toString(),
                                    q.value(6).toInt(), q.value(7).toDate(), q.value(8).toInt(),
                                    q.value(9).toInt());
            return p;
        }
    return NULL;
}

int PatientDAO::getNumberOfPatient(){
    q.exec("SELECT count(*) FROM TPatient");
    while (q.next()) {
            return q.value(0).toInt();
        }
    return 0;
}

void PatientDAO::printPatients(){
    q.exec("SELECT Nom FROM TPatient WHERE Id = 1");
    while (q.next()) {
            QString name = q.value(0).toString();
            cout<<name.toStdString()<<endl;
        }
}
