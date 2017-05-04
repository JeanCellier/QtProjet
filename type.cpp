#include "type.h"

Type::Type(int id, QString label)
{
    this->id = id;
    this->label = label;
}

int Type::getId(){
    return this->id;
}

QString Type::getLabel(){
    return this->label;
}
