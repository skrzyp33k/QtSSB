/**
 * @file addphonedialog.cpp
 * @brief Plik źródłowy klasy AddPhoneDialog
 * @see AddPhoneDialog
 */
#include "addphonedialog.h"
#include "ui_addphonedialog.h"

AddPhoneDialog::AddPhoneDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPhoneDialog)
{
    ui->setupUi(this);
    this->ui->phoneLineEdit->setValidator( new QIntValidator(0, 999999999, this) );
}

AddPhoneDialog::~AddPhoneDialog()
{
    delete ui;
}

void AddPhoneDialog::popUp()
{
    this->ui->phoneLineEdit->setFocus();
    this->ui->phoneLineEdit->setText("");
    this->show();
}

void AddPhoneDialog::on_buttonBox_accepted()
{
    attrib = this->ui->phoneLineEdit->text();

    emit closed();
    this->close();
}

