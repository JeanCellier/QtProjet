#include "Patient.h"

Patient::Patient(int id, QString name, QString firstName, QString address, QString city,
                 QString zipCode, QString comment, int phoneNumber, QDate consultDate, int consultTime, int priority) {
    this->id = id;
    this->name = name;
    this->firstName = firstName;
    this->address = address;
    this->city = city;
    this->zipCode = zipCode;
    this->comment = comment;
    this->phoneNumber = phoneNumber;
    this->consultDate = consultDate;
    this->consultTime = consultTime;
    this->priority = priority;
}

int Patient::getId() {
    return this->id;
}

QString Patient::getFirstName() {
    return this->firstName;
}

QString Patient::getName() {
    return this->name;
}

QString Patient::getAddress() {
    return this->address;
}

QString Patient::getCity() {
    return this->city;
}

QString Patient::getZipCode() {
    return this->zipCode;
}

QString Patient::getComment() {
    return this->comment;
}

int Patient::getPhoneNumber() {
    return this->phoneNumber;
}

QDate Patient::getConsultDate() {
    return this->consultDate;
}

int Patient::getConsultTime() {
    return this->consultTime;
}


int Patient::getPriority() {
    return this->priority;
}
