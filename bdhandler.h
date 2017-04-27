#ifndef BDHANDLER_H
#define BDHANDLER_H
#include <QSqlQuery>

class Bdhandler
{
    public:
       Bdhandler();
       QSqlQuery openBD(void);
       void closeBD(void);
};


#endif // BDHANDLER_H
