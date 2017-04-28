#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Patient
{
private :
    string sFirstName;
    string sLastName;
    string sAddress;
    string sCity;
    string sComments;

    int iPhoneNumber;
    int iPostalCode;
    int iConsultationEstimatedTime;
    int iPriority;

    vector<int> viIdRessources;

public :
    Patient(string firstName, string lastName, string address, string city,
        string comments, int phoneNumber, int postalCode,
        int consultationEstimatedTime, int priority);

    string GetFirstName();

    string GetLastName();

    int GetPriority();

    int GetConsultationEstimatedTime();
};

#endif // PATIENT_H
