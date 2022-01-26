#include "contactinfodialog.h"
#include "ui_contactinfodialog.h"

#include "qossbcontact.h"

ContactInfoDialog::ContactInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactInfoDialog)
{
    ui->setupUi(this);
}

ContactInfoDialog::~ContactInfoDialog()
{
    delete ui;
}

void ContactInfoDialog::popUp(QObject *obj)
{
    this->obj = obj;
    ui->name->setText(dynamic_cast<QOSSBContact*>(obj)->name);
    ui->surname->setText(dynamic_cast<QOSSBContact*>(obj)->surname);
    ui->description->setText(dynamic_cast<QOSSBContact*>(obj)->description);

    this->show();
}
