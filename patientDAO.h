#ifndef PATIENTDAO_H
#define PATIENTDAO_H
#include <QString>
#include <QDate>
#include "BdHandler.h"
#include <QSqlQuery>
#include "Patient.h"

class PatientDAO
{

private:
    Bdhandler handler;
    QSqlQuery q;
public:
    PatientDAO();
    ~PatientDAO();

    void addPatient(int id, QString name, QString firstName, QString address, QString city, QString zipCode, QString comment, QString phoneNumber, QDate consultDate, int consultTime, int priority);
    Patient* getPatientById(int id);
    Patient* getPatientByName(QString nom, QString prenom);
    vector<Patient*> getPatientsByValues(int id, QString name, QString firstName, QString startConsultDate, QString endConsultDate);
    vector<Patient*> getAllPatients();
    void modifyPatient(int id, QString name, QString firstName, QString address, QString city, QString zipCode, QString comment, QString phoneNumber, QDate consultDate, int consultTime, int priority);
    void deletePatientById(int id);
    void deletePatientByName(QString name, QString firstName);
    int getNumberOfPatient();
    int getMaxPatientId();

private:
};

#endif // PATIENTDAO_H
