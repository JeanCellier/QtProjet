#ifndef COMPTEDAO_H
#define COMPTEDAO_H
#include <QString>
#include <QDate>
#include "BdHandler.h"
#include <QSqlQuery>
#include "compte.h"

/**
 * @brief The CompteDAO class
 * Class handling the creation, modification and removal of Comptes entries in the database.
 */

class CompteDAO
{
    private:
        Bdhandler handler;
        QSqlQuery q;
    public:
        CompteDAO();
        ~CompteDAO();

        /**
         * @brief addCompte
         * Method adding a Compte in the database
         * @param id
         * @param idRessource
         * @param login
         * @param mdp
         */
        void addCompte(int id, int idRessource, QString login, QString mdp);

        /**
         * @brief getCompteById
         * Method getting a particular Compte entry in the database by its id
         * @param id
         * @return
         */
        Compte * getCompteById(int id);

        /**
         * @brief getCompteByIdRessource
         * Method getting a particular Compte entry in the database by its ressource id
         * @param idRessource
         * @return
         */
        Compte * getCompteByIdRessource(int idRessource);

        /**
         * @brief getCompteByLogin
         * Method getting a particular Compte in the database by its login
         * @param login
         * @return
         */
        Compte * getCompteByLogin(QString login);

        /**
         * @brief modifyCompte
         * Method modifying a Compte in the database
         * @param id
         * @param idRessource
         * @param login
         * @param mdp
         */
        void modifyCompte(int id, int idRessource, QString login, QString mdp);

        /**
         * @brief deleteCompteById
         * Method deleting a Compte in the database by its id
         * @param id
         */
        void deleteCompteById(int id);

        /**
         * @brief getNumberOfCompte
         * Method returning the total number of Compte entries in the database
         * @return
         */
        int getNumberOfCompte();

        /**
         * @brief getMaxCompteId
         * Method getting the maximum id in the Compte table
         * @return
         */
        int getMaxCompteId();
};
#endif // COMPTEDAO_H
