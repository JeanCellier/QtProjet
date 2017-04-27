#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include <QDate>
#include <QSqlQuery>

class patientDAO
{

private:
    QSqlQuery q;
public:
    patientDAO();
    ~patientDAO();

    void addPatient(int id, QString name, QString firstName, QString address, QString city, QString zipCode, QString comment, int phoneNumber, QDate consultDate, int consultTime, int priority);
    void deletePatientById(int id);
    void deletePatientByName(QString name, QString fistName);

private:
};

#endif // PATIENT_H
