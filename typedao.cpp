#include "typedao.h"

using namespace std;

TypeDAO::TypeDAO()
{
}

TypeDAO::~TypeDAO()
{
}

void TypeDAO::addType(int id, QString label){
    this->q = handler.openBD();
    q.exec("INSERT INTO TType "
           "SELECT '"+QString::number(id)+"' AS 'Id', "+label+" AS 'IdType'");
    handler.closeBD();
}

Type* TypeDAO::getTypeById(int id){
    this->q = handler.openBD();
    q.exec("SELECT Label FROM TType WHERE Id = "+QString::number(id)+"");
    while (q.next()) {
            Type* t = new Type(id, q.value(0).toString());
            handler.closeBD();
            return t;
        }
    handler.closeBD();
    return NULL;
}

int TypeDAO::getNumberOfType(){
    this->q = handler.openBD();
    q.exec("SELECT count(*) FROM TType");
    while (q.next()) {
            int numberOfType = q.value(0).toInt();
            handler.closeBD();
            return numberOfType;
        }
    handler.closeBD();
    return 0;
}

int TypeDAO::getMaxTypeId(){
    this->q = handler.openBD();
    q.exec("SELECT max(id) FROM TType");
    while (q.next()) {
            int maxTypeId = q.value(0).toInt();
            handler.closeBD();
            return maxTypeId;
        }
    handler.closeBD();
    return 0;
}
