#ifndef TYPE_H
#define TYPE_H
#include "QString"

/**
 * @brief The Type class
 * Model class representing a Type in the database
 */

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
