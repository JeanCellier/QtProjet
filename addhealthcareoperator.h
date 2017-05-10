#ifndef ADDHEALTHCAREOPERATOR_H
#define ADDHEALTHCAREOPERATOR_H

#include <QDialog>

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
    void on_typeBox_currentTextChanged(const QString &arg1);

    void on_cancelButton_clicked();

    void on_addButton_clicked();

private:
    Ui::addHealthcareOperator *ui;
};

#endif // ADDHEALTHCAREOPERATOR_H
