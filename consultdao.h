#ifndef CONSULTDAO_H
#define CONSULTDAO_H

#include <QString>
#include "BdHandler.h"
#include <QSqlQuery>
#include "consult.h"
#include "ressource.h"

using namespace std;

/**
 * @brief The ConsultDAO class
 * Class handling the creation, modification and removal of Consults entries in the database.
 */

class ConsultDAO
{
private:
    Bdhandler handler;
    QSqlQuery q;
public:
    ConsultDAO();
    ~ConsultDAO();

    /**
     * @brief addConsult
     * Method adding a consult in the database
     * @param id
     * @param idPatient
     * @param idRessource
     */
    void addConsult(int id, int idPatient, int idRessource);

    /**
     * @brief getConsultById
     * Method getting a consult in the database by its id
     * @param id
     * @return
     */
    Consult * getConsultById(int id);

    /**
     * @brief deleteConsultById
     * Method deleting a consult in the database by its id
     * @param id
     */
    void deleteConsultById(int id);

    /**
     * @brief deleteConsultByValues
     * Method deleting a consult in the database by its patient id and ressource id
     * @param idPatient
     * @param idRessource
     */
    void deleteConsultByValues(int idPatient, int idRessource);

    /**
     * @brief getNumberOfConsult
     * Method getting the total number of consult entries in the database
     * @return
     */
    int getNumberOfConsult();

    /**
     * @brief getMaxConsultId
     * Method getting the maximum id in the consult table
     * @return
     */
    int getMaxConsultId();

    /**
     * @brief getRessourceByIdPatient
     * Method getting the set of ressources assigned to a patient
     * @param idPatient
     * @return
     */
    vector<Ressource*> getRessourceByIdPatient(int idPatient);
};

#endif // CONSULTDAO_H
