#ifndef COMPTEDAO_H
#define COMPTEDAO_H
#include <QString>
#include <QDate>
#include "BdHandler.h"
#include <QSqlQuery>
#include "compte.h"

class CompteDAO
{

private:
    Bdhandler handler;
    QSqlQuery q;
public:
    CompteDAO();
    ~CompteDAO();

    void addCompte(int id, int idRessource, QString login, QString mdp);
    Compte * getCompteById(int id);
    Compte * getCompteByIdRessource(int idRessource);
    Compte * getCompteByLogin(QString login);
    void modifyCompte(int id, int idRessource, QString login, QString mdp);
    void deleteCompteById(int id);
    void deleteCompte0ByRessource(int idRessource);
    int getNumberOfCompte();
    int getMaxCompteId();
};
#endif // COMPTEDAO_H
