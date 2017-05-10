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
           "SELECT '" +id+"' AS 'Id', '"+name+"' AS 'Nom', '"+firstName+"' AS 'Prenom', '"+address+"' AS 'Adresse', '"+city+"' AS 'Ville', '"+zipCode+"' AS 'CP'"
           ", '"+comment+"' AS 'Commentaire', '"+phoneNumber+"' AS 'Tel', '"+consultDate.toString("yyyy.dd.MM")+"' AS 'DateConsultation', '"+consultTime+"' AS 'DureeConsultation', '"+priority+"' AS 'Priorite'");
}
