/**
 * @file userlogindialog.cpp
 * @brief Plik źródłowy klasy UserLoginDialog
 * @see UserLoginDialog
 */
#include "userlogindialog.h"
#include "ui_userlogindialog.h"

UserLoginDialog::UserLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserLoginDialog)
{
    ui->setupUi(this);
}

UserLoginDialog::~UserLoginDialog()
{
    delete ui;
}

void UserLoginDialog::popUp()
{
    this->ui->username->setFocus();

    if(!attrib.isEmpty()) attrib.clear();
    attrib.push_back("");
    attrib.push_back("");

    this->open();
}

void UserLoginDialog::on_buttonBox_accepted()
{
    attrib.clear();

    attrib.push_back(this->ui->username->text());
    attrib.push_back(this->ui->password->text());

    this->ui->username->setText("");
    this->ui->password->setText("");

    emit closed();
    this->close();
}

