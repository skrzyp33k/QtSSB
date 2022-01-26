#ifndef ADDADDRESSDIALOG_H
#define ADDADDRESSDIALOG_H

#include <QDialog>
#include <QVector>

namespace Ui {
class AddAddressDialog;
}

class AddAddressDialog : public QDialog
{
    Q_OBJECT

signals:
    void closed();

public:
    explicit AddAddressDialog(QWidget *parent = nullptr);
    ~AddAddressDialog();

    void popUp();

    QVector<QString> attrib;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddAddressDialog *ui;
};

#endif // ADDADDRESSDIALOG_H
