#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <QString>
#include <QDate>

using namespace std;

class Patient
{
private :
    int id;
    QString name;
    QString firstName;
    QString address;
    QString city;
    QString zipCode;
    QString comment;

    int phoneNumber;
    QDate consultDate;
    int consultTime;
    int priority;

public :
    Patient(int id, QString name, QString firstName, QString address, QString city, QString zipCode,
            QString comment, int phoneNumber, QDate consultDate, int consultTime, int priority);
    int getId();
    QString getFirstName();
    QString getName();
    QString getAddress();
    QString getCity();
    QString getZipCode();
    QString getComment();

    int getPhoneNumber();
    QDate getConsultDate();
    int getConsultTime();
    int getPriority();
};

#endif // PATIENT_H
