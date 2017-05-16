#ifndef RESSOURCEDAO_H
#define RESSOURCEDAO_H
#include <QSqlQuery>
#include <QVariant>
#include "BdHandler.h"
#include "ressource.h"
#include <map>

using namespace std;

/**
 * @brief The RessourceDAO class
 * Class handling the creation, modification and removal of Ressources entries in the database.
 */

class RessourceDAO
{
private:
    Bdhandler handler;
    QSqlQuery q;
public:
    RessourceDAO();
    ~RessourceDAO();

    /**
     * @brief addRessource
     * Method adding a ressource in the database
     * @param id
     * @param name
     * @param firstName
     * @param idType
     */
    void addRessource(int id, QString name, QString firstName, int idType);

    /**
     * @brief getRessourceById
     * Method getting a ressource in the database by its id
     * @param id
     * @return
     */
    Ressource* getRessourceById(int id);

    /**
     * @brief getRessourceByName
     * Method getting a ressource in the database by its name
     * @param name
     * @param firstName
     * @return
     */
    Ressource* getRessourceByName(QString name, QString firstName);

    /**
     * @brief modifyRessource
     * Method modifying a ressource in the database
     * @param id
     * @param name
     * @param firstName
     * @param idType
     */
    void modifyRessource(int id, QString name, QString firstName, int idType);

    /**
     * @brief getRessourcesByIdType
     * Method getting all the ressources by type id
     * @param idType
     * @return
     */
    vector<Ressource*> getRessourcesByIdType(int idType);

    /**
     * @brief deleteRessourceById
     * Method deleting a ressource by its id
     * @param id
     */
    void deleteRessourceById(int id);

    /**
     * @brief deleteRessourceByName
     * Method deleting a ressource by its name
     * @param name
     * @param firstName
     */
    void deleteRessourceByName(QString name, QString firstName);

    /**
     * @brief getNumberOfRessourceByIdType
     * Method getting the ressources by a given type
     * @param idType
     * @return
     */
    int getNumberOfRessourceByIdType(int idType);

    /**
     * @brief getNumberOfRessource
     * Method getting the total number of ressources in the database
     * @return
     */
    int getNumberOfRessource();

    /**
     * @brief getMaxRessourceId
     * Method getting the maximum id in the ressource table
     * @return
     */
    int getMaxRessourceId();

    /**
     * @brief getRessourcesFullNames
     * Method getting the id/full name for every ressource in the database
     * @return
     */
    map<int, QString> getRessourcesFullNames();

};

#endif // RESSOURCEDAO_H
