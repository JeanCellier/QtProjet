#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <QString>

class Ressource
{
private :
    int id;
    QString name;
    QString firstName;
    int idType;

public:
    Ressource(int id, QString name, QString firstName, int idType);
    int getId();
    QString getName();
    QString getFirstName();
    int getIdType();
};

#endif // RESSOURCE_H
