#ifndef CONSULTDAO_H
#define CONSULTDAO_H

#include <QString>
#include "BdHandler.h"
#include <QSqlQuery>
#include "consult.h"
#include "ressource.h"

using namespace std;

class ConsultDAO
{
private:
    Bdhandler handler;
    QSqlQuery q;
public:
    ConsultDAO();
    ~ConsultDAO();

    void addConsult(int id, int idPatient, int idRessource);
    Consult * getConsultById(int id);
    void deleteConsultById(int id);
    int getNumberOfConsult();
    int getMaxConsultId();
    vector<Ressource*> getRessourceByIdPatient(int idPatient);
};

#endif // CONSULTDAO_H
