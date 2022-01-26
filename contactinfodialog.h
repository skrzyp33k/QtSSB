#ifndef CONTACTINFODIALOG_H
#define CONTACTINFODIALOG_H

#include <QDialog>
#include <QObject>

namespace Ui {
class ContactInfoDialog;
}

class ContactInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ContactInfoDialog(QWidget *parent = nullptr);
    ~ContactInfoDialog();

    void popUp(QObject *obj);

private:
    Ui::ContactInfoDialog *ui;

    QObject* obj;

};

#endif // CONTACTINFODIALOG_H
