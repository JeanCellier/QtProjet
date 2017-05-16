#ifndef BDHANDLER_H
#define BDHANDLER_H
#include <QSqlQuery>

/**
 * Class handling the database connections
 */

class Bdhandler
{
    public:
       Bdhandler();

       /**
        * @brief openBD
        * Opens the database
        * @return
        */
       QSqlQuery openBD(void);

       /**
        * @brief closeBD
        * Closes the database
        */
       void closeBD(void);
};


#endif // BDHANDLER_H
