#ifndef TYPEDAO_H
#define TYPEDAO_H
#include <QSqlQuery>
#include "QString"
#include <QVariant>
#include "BdHandler.h"
#include "type.h"

class TypeDAO
{
private:
    Bdhandler handler;
    QSqlQuery q;
public:
    TypeDAO();
    ~TypeDAO();

    void addType(int id, QString label);
    Type* getTypeById(int id);
    void deleteTypeById(int id);
    int getNumberOfType();
};

#endif // TYPEDAO_H
