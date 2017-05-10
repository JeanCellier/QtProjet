#include "compte.h"

Compte::Compte(int id, int idRessource, QString login, QString mdp)
{
    this->id = id;
    this->idRessource = idRessource;
    this->login = login;
    this->mdp = mdp;
}

int Compte::getId(){
    return this->id;
}

int Compte::getIdRessource(){
    return this->idRessource;
}

QString Compte::getLogin(){
    return this->login;
}

QString Compte::getMdp(){
    return this->mdp;
}
