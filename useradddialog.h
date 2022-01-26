#ifndef USERADDDIALOG_H
#define USERADDDIALOG_H

#include <QDialog>

namespace Ui {
class UserAddDialog;
}

class UserAddDialog : public QDialog
{
    Q_OBJECT

signals:
    void closed();

public:
    explicit UserAddDialog(QWidget *parent = nullptr);
    ~UserAddDialog();

    QVector<QString> attrib;

    void popUp();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::UserAddDialog *ui;
};

#endif // USERADDDIALOG_H
