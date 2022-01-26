#include "ssbaddress.h"

SSBAddress::SSBAddress(int id, int id_contact, QString fline, QString sline, QString postal, QString city)
{
    this->id = id;
    this->id_contact = id_contact;
    this->fline = fline;
    this->sline = sline;
    this->postal = postal;
    this->city = city;
}

SSBAddress::SSBAddress(int id_contact, QString fline, QString sline, QString postal, QString city)
{
    this->id_contact = id_contact;
    this->fline = fline;
    this->sline = sline;
    this->postal = postal;
    this->city = city;

    QSqlQuery query;
    query.exec("SELECT MAX(id_address) FROM addresses;");
    while(query.next())
    {
        this->id = query.value(0).toInt() + 1;
    }

    query.exec(this->getInsertQuery());
}

QString SSBAddress::getInsertQuery()
{
    qDebug() <<  "INSERT INTO addresses VALUES (" + QVariant(this->id).toString() +
                 ",\'" + QVariant(this->id_contact).toString() +
                  "\',\'" + this->fline +
                 "\',\'" + this->sline +
                 "\',\'" + this->postal +
                 "\',\'" + this->city + "\');";

    return "INSERT INTO addresses VALUES (" + QVariant(this->id).toString() +
            ",\'" + QVariant(this->id_contact).toString() +
             "\',\'" + this->fline +
            "\',\'" + this->sline +
            "\',\'" + this->postal +
            "\',\'" + this->city + "\');";
}

QString SSBAddress::getDeleteQuery()
{
    return "DELETE FROM addresses WHERE id_address = " + QVariant(this->id).toString() + ";";
}

