#ifndef C_INIT_BD_H
#define C_INIT_BD_H
#include <QSqlDatabase>
#include <QDate>

/**
 * Class filling the database at the start of the application
 */

class C_INIT_BD
{
    private:
        C_INIT_BD();

    public:
        static bool Creation_BD(void);
};

#endif // C_INIT_BD_H
