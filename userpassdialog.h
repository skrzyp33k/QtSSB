#ifndef USERPASSDIALOG_H
#define USERPASSDIALOG_H

#include <QDialog>

namespace Ui {
class UserPassDialog;
}

class UserPassDialog : public QDialog
{
    Q_OBJECT

signals:
    void closed();

public:
    explicit UserPassDialog(QWidget *parent = nullptr);
    ~UserPassDialog();

    QVector<QString> attrib;

    void popUp();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::UserPassDialog *ui;
};

#endif // USERPASSDIALOG_H
