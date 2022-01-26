/**
 * @file useradddialog.cpp
 * @brief Plik źródłowy klasy UserAddDialog
 * @see UserAddDialog
 */
#include "useradddialog.h"
#include "ui_useradddialog.h"

UserAddDialog::UserAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserAddDialog)
{
    ui->setupUi(this);
}

UserAddDialog::~UserAddDialog()
{
    delete ui;
}

void UserAddDialog::popUp()
{
    this->ui->username->setFocus();

    if(!attrib.isEmpty()) attrib.clear();
    attrib.push_back("");
    attrib.push_back("");
    attrib.push_back("");

    this->open();
}

void UserAddDialog::on_buttonBox_accepted()
{
    attrib.clear();

    attrib.push_back(this->ui->username->text());
    attrib.push_back(this->ui->password->text());
    attrib.push_back(this->ui->repeat->text());

    this->ui->username->setText("");
    this->ui->password->setText("");
    this->ui->repeat->setText("");

    emit closed();
    this->close();
}

