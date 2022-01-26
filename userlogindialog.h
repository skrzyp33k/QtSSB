#ifndef USERLOGINDIALOG_H
#define USERLOGINDIALOG_H

#include <QDialog>

namespace Ui {
class UserLoginDialog;
}

class UserLoginDialog : public QDialog
{
    Q_OBJECT

signals:
    void closed();

public:
    explicit UserLoginDialog(QWidget *parent = nullptr);
    ~UserLoginDialog();

    QVector<QString> attrib;

    void popUp();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::UserLoginDialog *ui;
};

#endif // USERLOGINDIALOG_H
