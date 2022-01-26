#ifndef ADDPHONEDIALOG_H
#define ADDPHONEDIALOG_H

#include <QDialog>
#include <QIntValidator>

namespace Ui {
class AddPhoneDialog;
}

class AddPhoneDialog : public QDialog
{
    Q_OBJECT

signals:
    void closed();

public:
    explicit AddPhoneDialog(QWidget *parent = nullptr);
    ~AddPhoneDialog();

    QString attrib;

    void popUp();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddPhoneDialog *ui;
};

#endif // ADDPHONEDIALOG_H
