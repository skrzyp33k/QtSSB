#include "userpassdialog.h"
#include "ui_userpassdialog.h"

UserPassDialog::UserPassDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserPassDialog)
{
    ui->setupUi(this);
}

UserPassDialog::~UserPassDialog()
{
    delete ui;
}

void UserPassDialog::popUp()
{
    this->ui->oldpass->setFocus();

    if(!attrib.isEmpty()) attrib.clear();
    attrib.push_back("");
    attrib.push_back("");

    this->open();
}

void UserPassDialog::on_buttonBox_accepted()
{
    attrib.clear();

    attrib.push_back(this->ui->oldpass->text());
    attrib.push_back(this->ui->newpass->text());
    attrib.push_back(this->ui->repeatpass->text());

    this->ui->oldpass->setText("");
    this->ui->newpass->setText("");
    this->ui->repeatpass->setText("");

    emit closed();
    this->close();
}

