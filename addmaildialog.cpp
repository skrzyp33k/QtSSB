/**
 * @file addmaildialog.cpp
 * @brief Plik źródłowy klasy AddMailDialog
 * @see AddMailDialog
 */
#include "addmaildialog.h"
#include "ui_addmaildialog.h"

AddMailDialog::AddMailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMailDialog)
{
    ui->setupUi(this);
}

AddMailDialog::~AddMailDialog()
{
    delete ui;
}

void AddMailDialog::popUp()
{
    this->ui->mailLineEdit->setFocus();
    this->ui->mailLineEdit->setText("");
    this->show();
}

void AddMailDialog::on_buttonBox_accepted()
{
    attrib = this->ui->mailLineEdit->text();

    emit closed();
    this->close();
}

