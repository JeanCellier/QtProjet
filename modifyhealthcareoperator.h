#ifndef MODIFYHEALTHCAREOPERATOR_H
#define MODIFYHEALTHCAREOPERATOR_H

#include <QDialog>
#include "ressource.h"

/**
 * Class allowing the creation of the modifyhealthcareoperator window
 * This window allows the user to modify a ressource in the database
 */

namespace Ui {
class ModifyHealthcareOperator;
}

class ModifyHealthcareOperator : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyHealthcareOperator(QWidget *parent = 0);
    ~ModifyHealthcareOperator();

    /**
     * @brief setRessource
     * Sets the fields of the window with the previously selected ressource
     * @param ressource
     */
    void setRessource(Ressource* ressource);

private slots:

    /**
     * @brief on_modifyButton_clicked
     * Event method when the modify button is clicked
     */
    void on_modifyButton_clicked();

    /**
     * @brief on_cancelButton_clicked
     * Event method when the cancel button is clicked
     */
    void on_cancelButton_clicked();

    /**
     * @brief on_typeBox_currentTextChanged
     * Event method when the type selected changes
     * @param arg1
     */
    void on_typeBox_currentTextChanged(const QString &arg1);

private:
    Ui::ModifyHealthcareOperator *ui;
    Ressource* ressource;
};

#endif // MODIFYHEALTHCAREOPERATOR_H
