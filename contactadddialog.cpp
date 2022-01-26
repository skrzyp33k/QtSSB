/**
 * @file contactadddialog.cpp
 * @brief Plik źródłowy klasy ContactAddDialog
 * @see ContactAddDialog
 */
#include "contactadddialog.h"
#include "ui_contactadddialog.h"

ContactAddDialog::ContactAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactAddDialog)
{
    ui->setupUi(this);

    this->ui->name->setFocus();
}

ContactAddDialog::~ContactAddDialog()
{
    delete ui;
}

void ContactAddDialog::popUp()
{
    this->ui->name->setFocus();

    if(!attrib.isEmpty()) attrib.clear();
    attrib.push_back("");
    attrib.push_back("");
    attrib.push_back("");

    this->open();
}

void ContactAddDialog::on_buttonBox_accepted()
{
    attrib.clear();

    attrib.push_back(this->ui->name->text());
    attrib.push_back(this->ui->surname->text());
    attrib.push_back(this->ui->description->toPlainText());

    this->ui->name->setText("");
    this->ui->surname->setText("");
    this->ui->description->document()->setPlainText("");

    emit closed();
    this->close();
}

