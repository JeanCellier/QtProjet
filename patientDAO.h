#ifndef PATIENTDAO_H
#define PATIENTDAO_H
#include <QString>
#include <QDate>
#include "BdHandler.h"
#include <QSqlQuery>
#include "Patient.h"

/**
 * @brief The PatientDAO class
 * Class handling the creation, modification and removal of Patients entries in the database.
 */

class PatientDAO
{

private:
    Bdhandler handler;
    QSqlQuery q;
public:
    PatientDAO();
    ~PatientDAO();

    /**
     * @brief addPatient
     * Method adding a patient in the database
     * @param id
     * @param name
     * @param firstName
     * @param address
     * @param city
     * @param zipCode
     * @param comment
     * @param phoneNumber
     * @param consultDate
     * @param consultTime
     * @param priority
     */
    void addPatient(int id, QString name, QString firstName, QString address, QString city, QString zipCode, QString comment, QString phoneNumber, QDate consultDate, int consultTime, int priority);

    /**
     * @brief getPatientById
     * Method getting a patient in the database by its id
     * @param id
     * @return
     */
    Patient* getPatientById(int id);

    /**
     * @brief getPatientByName
     * Method getting a patient by its name
     * @param nom
     * @param prenom
     * @return
     */
    Patient* getPatientByName(QString nom, QString prenom);

    /**
     * @brief getPatientsByValues
     * Method getting a patient in the database by its id, name and consult date
     * @param id
     * @param name
     * @param firstName
     * @param startConsultDate
     * @param endConsultDate
     * @return
     */
    vector<Patient*> getPatientsByValues(int id, QString name, QString firstName, QString startConsultDate, QString endConsultDate);

    /**
     * @brief getAllPatients
     * Method getting all the patients in the database
     * @return
     */
    vector<Patient*> getAllPatients();

    /**
     * @brief modifyPatient
     * Method modifying a patient in the database
     * @param id
     * @param name
     * @param firstName
     * @param address
     * @param city
     * @param zipCode
     * @param comment
     * @param phoneNumber
     * @param consultDate
     * @param consultTime
     * @param priority
     */
    void modifyPatient(int id, QString name, QString firstName, QString address, QString city, QString zipCode, QString comment, QString phoneNumber, QDate consultDate, int consultTime, int priority);

    /**
     * @brief deletePatientById
     * Method deleting a patient in the database by its id
     * @param id
     */
    void deletePatientById(int id);

    /**
     * @brief deletePatientByName
     * Method deleting a patient by name
     * @param name
     * @param firstName
     */
    void deletePatientByName(QString name, QString firstName);

    /**
     * @brief getNumberOfPatient
     * Method getting the total number of patient entries in the database
     * @return
     */
    int getNumberOfPatient();

    /**
     * @brief getMaxPatientId
     * Method getting the maximum id of the patient table
     * @return
     */
    int getMaxPatientId();

private:
};

#endif // PATIENTDAO_H
