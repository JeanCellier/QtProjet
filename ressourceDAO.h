#ifndef RESSOURCEDAO_H
#define RESSOURCEDAO_H
#include <QSqlQuery>
#include <QVariant>
#include "BdHandler.h"
#include "ressource.h"

using namespace std;

class RessourceDAO
{
private:
    Bdhandler handler;
    QSqlQuery q;
public:
    RessourceDAO();
    ~RessourceDAO();

    void addRessource(int id, QString name, QString firstName, int idType);
    Ressource* getRessourceById(int id);
    Ressource* getRessourceByName(QString name, QString firstName);
    vector<Ressource*> getRessourcesByIdType(int idType);
    void deleteRessourceById(int id);
    void deleteRessourceByName(QString name, QString fistName);
    int getNumberOfRessourceByIdType(int idType);
    int getNumberOfRessource();
    int getMaxRessourceId();

};

#endif // RESSOURCEDAO_H
