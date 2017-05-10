#include "Ressource.h"

Ressource::Ressource(int id, QString name, QString firstName, int idType)
{
    this->id = id;
    this->name = name;
    this->firstName = firstName;
    this->idType = idType;
}

int Ressource::getId(){
    return this->id;
}

QString Ressource::getName(){
    return this->name;
}

QString Ressource::getFirstName(){
    return this->firstName;
}

int Ressource::getIdType(){
    return this->idType;
}
