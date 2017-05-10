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

    void addPatient(int id, QString name, QString firstName, QString address, QString city, QString zipCode, QString comment, int phoneNumber, QDate consultDate, int consultTime, int priority);
    Patient* getPatientById(int id);
    void deletePatientById(int id);
    void deletePatientByName(QString name, QString fistName);
    int getNumberOfPatient();
    int getMaxPatientId();

private:
};

#endif // PATIENTDAO_H
