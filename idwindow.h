#ifndef IDWINDOW_H
#define IDWINDOW_H

#include <QDialog>

namespace Ui {
class IdWindow;
}

class IdWindow : public QDialog
{
    Q_OBJECT

public:
    explicit IdWindow(QWidget *parent = 0);
    bool isIdValid();
    ~IdWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::IdWindow *ui;
};

#endif // IDWINDOW_H
