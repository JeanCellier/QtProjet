#ifndef ADDHEALTHCAREOPERATOR_H
#define ADDHEALTHCAREOPERATOR_H

#include <QDialog>

/**
 * Class allowing the creation of the addhealthcareoperator window
 * This window allows the user to create a ressource in the database
 */

namespace Ui {
class addHealthcareOperator;
}

class addHealthcareOperator : public QDialog
{
    Q_OBJECT

public:
    explicit addHealthcareOperator(QWidget *parent = 0);
    ~addHealthcareOperator();

private slots:
    /**
     * @brief on_typeBox_currentTextChanged
     * Event method when the selected type changes
     * @param arg1
     */
    void on_typeBox_currentTextChanged(const QString &arg1);

    /**
     * @brief on_cancelButton_clicked
     * Event method when the cancel button is clicked
     */
    void on_cancelButton_clicked();

    /**
     * @brief on_addButton_clicked
     * Event method when the add button is clicked
     */
    void on_addButton_clicked();

private:
    Ui::addHealthcareOperator *ui;
};

#endif // ADDHEALTHCAREOPERATOR_H
