#ifndef CONTACTADDDIALOG_H
#define CONTACTADDDIALOG_H

#include <QDialog>

namespace Ui {
class ContactAddDialog;
}

class ContactAddDialog : public QDialog
{
    Q_OBJECT
signals:
    void closed();

public:
    explicit ContactAddDialog(QWidget *parent = nullptr);
    ~ContactAddDialog();

    QVector<QString> attrib;

    void popUp();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ContactAddDialog *ui;
};

#endif // CONTACTADDDIALOG_H
