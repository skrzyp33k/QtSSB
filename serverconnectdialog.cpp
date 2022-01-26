#include "serverconnectdialog.h"
#include "ui_serverconnectdialog.h"

ServerConnectDialog::ServerConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerConnectDialog)
{
    ui->setupUi(this);
}

ServerConnectDialog::~ServerConnectDialog()
{
    delete ui;
}

void ServerConnectDialog::popUp()
{
    this->ui->address->setFocus();

    if(!attrib.isEmpty()) attrib.clear();
    attrib.push_back("");
    attrib.push_back("");
    attrib.push_back("");
    attrib.push_back("");

    this->open();
}

void ServerConnectDialog::on_buttonBox_accepted()
{
    attrib.clear();

    attrib.push_back(this->ui->address->text());
    attrib.push_back(this->ui->username->text());
    attrib.push_back(this->ui->password->text());
    attrib.push_back(this->ui->database->text());

    this->ui->address->setText("");
    this->ui->username->setText("");
    this->ui->password->setText("");
    this->ui->database->setText("");

    emit closed();
    this->close();
}
