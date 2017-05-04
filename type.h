#ifndef TYPE_H
#define TYPE_H
#include "QString"

class Type
{
private:
    int id;
    QString label;
public:
    Type(int id, QString label);
    int getId();
    QString getLabel();
};

#endif // TYPE_H
