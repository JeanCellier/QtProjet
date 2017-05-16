#ifndef TYPEDAO_H
#define TYPEDAO_H
#include <QSqlQuery>
#include "QString"
#include <QVariant>
#include "BdHandler.h"
#include "type.h"

/**
 * @brief The TypeDAO class
 * Class handling the creation, modification and removal of Types entries in the database.
 */

class TypeDAO
{
    private:
        Bdhandler handler;
        QSqlQuery q;
    public:
        TypeDAO();
        ~TypeDAO();

        /**
         * @brief addType
         * Method adding a type in the database
         * @param id
         * @param label
         */
        void addType(int id, QString label);

        /**
         * @brief getTypeById
         * Method getting a type in the database by its id
         * @param id
         * @return
         */
        Type* getTypeById(int id);

        /**
         * @brief deleteTypeById
         * Method deleting a type in the database by its id
         * @param id
         */
        void deleteTypeById(int id);

        /**
         * @brief getNumberOfType
         * Method getting the total number of type entries in the database
         * @return
         */
        int getNumberOfType();

        /**
         * @brief getMaxTypeId
         * Method getting the maximum id in the type table
         * @return
         */
        int getMaxTypeId();

        /**
         * @brief getTypeIdByName
         * Method getting a type in the database by its name
         * @param label
         * @return
         */
        int getTypeIdByName(QString label);
};

#endif // TYPEDAO_H
