#ifndef PATIENTDAO_H
#define PATIENTDAO_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include "Patient.h"

class PatientDAO
{

private:
    QSqlQuery q;
public:
    PatientDAO();
    ~PatientDAO();

    void addPatient(int id, QString name, QString firstName, QString address, QString city, QString zipCode, QString comment, int phoneNumber, QDate consultDate, int consultTime, int priority);
    Patient getPatientById(int id);
    void deletePatientById(int id);
    void deletePatientByName(QString name, QString fistName);
    void printPatients();

private:
};

#endif // PATIENTDAO_H
