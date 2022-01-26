/**
 * @file addaddressdialog.cpp
 * @brief Plik źródłowy klasy AddAddressDialog
 * @see AddAddressDialog
 */
#include "addaddressdialog.h"
#include "ui_addaddressdialog.h"

AddAddressDialog::AddAddressDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAddressDialog)
{
    ui->setupUi(this);
}

AddAddressDialog::~AddAddressDialog()
{
    delete ui;
}

void AddAddressDialog::popUp()
{
    if(!attrib.isEmpty()) attrib.clear();
    attrib.push_back("");
    attrib.push_back("");
    attrib.push_back("");
    attrib.push_back("");

    this->ui->flineLineEdit->setFocus();

    this->show();
}

void AddAddressDialog::on_buttonBox_accepted()
{
    attrib.clear();

    attrib.push_back(this->ui->flineLineEdit->text());
    attrib.push_back(this->ui->slineLineEdit->text());
    attrib.push_back(this->ui->postalLineEdit->text());
    attrib.push_back(this->ui->cityLineEdit->text());

    this->ui->flineLineEdit->setText("");
    this->ui->slineLineEdit->setText("");
    this->ui->postalLineEdit->setText("");
    this->ui->cityLineEdit->setText("");

    emit closed();
    this->close();
}
