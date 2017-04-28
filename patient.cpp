#include "Patient.h"

Patient::Patient(string firstName, string lastName, string address, string city,
    string comments, int phoneNumber, int postalCode,
    int consultationEstimatedTime, int priority) {
    sFirstName = firstName;
    sLastName = lastName;
    sAddress = address;
    sCity = city;
    sComments = comments;
    iPhoneNumber = phoneNumber;
    iPostalCode = postalCode;
    iConsultationEstimatedTime = consultationEstimatedTime;
    iPriority = priority;
}

string Patient::GetFirstName() {
    return sFirstName;
}

string Patient::GetLastName() {
    return sLastName;
}

int Patient::GetPriority() {
    return iPriority;
}

int Patient::GetConsultationEstimatedTime() {
    return iConsultationEstimatedTime;
}
