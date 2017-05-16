#ifndef COMPTE_H
#define COMPTE_H
#include <QString>

/**
 * @brief The Compte class
 * Model class representing a Compte in the database
 */

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
