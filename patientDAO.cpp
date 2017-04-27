#include "patientDAO.h"
#include <QSqlDatabase>
#include "bdhandler.h"

patientDAO::patientDAO()
{
    Bdhandler handler;
    this->q = handler.openBD();
}

patientDAO::~patientDAO()
{
    Bdhandler handler;
    handler.closeBD();
}

void patientDAO::addPatient(int id, QString name, QString firstName, QString address, QString city, QString zipCode, QString comment, int phoneNumber, QDate consultDate, int consultTime, int priority){
    q.exec("INSERT INTO TPatient "
           "SELECT '1' AS 'Id', 'Ricardo' AS 'Nom', 'Jacques' AS 'Prenom', '3 rue des justices' AS 'Adresse', 'Tours' AS 'Ville', '37200' AS 'CP'"
           ", 'Dépressif' AS 'Commentaire', '247558963' AS 'Commentaire', '2013-06-01' AS 'DateConsultation', '90' AS 'DureeConsultation', '2' AS 'Priorite'");
}
