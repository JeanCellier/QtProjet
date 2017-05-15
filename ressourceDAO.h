#ifndef RESSOURCEDAO_H
#define RESSOURCEDAO_H
#include <QSqlQuery>
#include <QVariant>
#include "BdHandler.h"
#include "ressource.h"
#include <map>

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
    void modifyRessource(int id, QString name, QString firstName, int idType);
    vector<Ressource*> getRessourcesByIdType(int idType);
    void deleteRessourceById(int id);
    void deleteRessourceByName(QString name, QString firstName);
    int getNumberOfRessourceByIdType(int idType);
    int getNumberOfRessource();
    int getMaxRessourceId();
    map<int, QString> getRessourcesFullNames();

};

#endif // RESSOURCEDAO_H
