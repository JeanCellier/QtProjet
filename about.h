#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

/**
 * Class allowing the creation of the about window
 */
namespace Ui {
class about;
}

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = 0);
    ~about();

private:
    Ui::about *ui;
};

#endif // ABOUT_H
