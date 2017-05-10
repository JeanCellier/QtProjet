#ifndef COMPTE_H
#define COMPTE_H
#include <QString>

class Compte
{
private:
    int id;
    int idRessource;
    QString login;
    QString mdp;
public:
    Compte(int id, int idRessource, QString login, QString mdp);
    int getId();
    int getIdRessource();
    QString getLogin();
    QString getMdp();
};

#endif // COMPTE_H
