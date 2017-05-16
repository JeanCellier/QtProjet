#ifndef IDWINDOW_H
#define IDWINDOW_H

#include <QDialog>

/**
 * Class allowing the creation of the identification window
 */

namespace Ui {
class IdWindow;
}

class IdWindow : public QDialog
{
    Q_OBJECT

public:
    explicit IdWindow(QWidget *parent = 0);

    /**
     * @brief isIdValid
     * Method looking if the login/password couple entered is present or not in the database
     * @return
     */
    bool isIdValid();
    ~IdWindow();

private slots:
    /**
     * @brief on_cancelButton_clicked
     * Event method when the cancel button is clicked
     */
    void on_cancelButton_clicked();

    /**
     * @brief on_connectButton_clicked
     * Event method when the connect button is clicked
     */
    void on_connectButton_clicked();

private:
    Ui::IdWindow *ui;
};

#endif // IDWINDOW_H
