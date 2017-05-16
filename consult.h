#ifndef CONSULT_H
#define CONSULT_H

/**
 * @brief The Compte class
 * Model class representing a Consult in the database
 */

class Consult
{
    private:
        int id;
        int idPatient;
        int idRessource;
    public:
        Consult(int id, int idPatient, int idRessource);
        int getId();
        int getIdPatient();
        int getIdRessource();
};

#endif // CONSULT_H
