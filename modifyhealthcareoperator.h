#ifndef MODIFYHEALTHCAREOPERATOR_H
#define MODIFYHEALTHCAREOPERATOR_H

#include <QDialog>
#include "ressource.h"

namespace Ui {
class ModifyHealthcareOperator;
}

class ModifyHealthcareOperator : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyHealthcareOperator(QWidget *parent = 0);
    ~ModifyHealthcareOperator();
    void setRessource(Ressource* ressource);

private slots:
    void on_modifyButton_clicked();

    void on_cancelButton_clicked();

    void on_typeBox_currentTextChanged(const QString &arg1);

private:
    Ui::ModifyHealthcareOperator *ui;
    Ressource* ressource;
};

#endif // MODIFYHEALTHCAREOPERATOR_H
