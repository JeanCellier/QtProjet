#include "consult.h"

Consult::Consult(int id, int idPatient, int idRessource)
{
    this->id = id;
    this->idPatient = idPatient;
    this->idRessource = idRessource;
}

int Consult::getId(){
    return this->id;
}

int Consult::getIdPatient(){
    return this->idPatient;
}

int Consult::getIdRessource(){
    return this->idRessource;
}
