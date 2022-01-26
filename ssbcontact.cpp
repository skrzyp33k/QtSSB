/**
 * @file ssbcontact.cpp
 * @brief Plik źródłowy klasy SSBContact
 * @see SSBContact
 */
#include "ssbcontact.h"

SSBContact::SSBContact(int id_contact, QString name, QString surname, QString description, QString owner)
{
    this->id = id_contact;
    this->name = name;
    this->surname = surname;
    this->description = description;
    this->owner = owner;
}

SSBContact::SSBContact(QString name, QString surname, QString description, QString owner)
{
    this->name = name;
    this->surname = surname;
    this->description = description;
    this->owner = owner;

    QSqlQuery query;
    query.exec("SELECT MAX(id_contact) FROM contacts;");
    while(query.next())
    {
        if(query.value(0).toString() == "0") this->id = 1;
        else this->id = query.value(0).toInt() + 1;
    }

    query.exec(this->getInsertQuery());
}

void SSBContact::setValues(QString name, QString surname, QString description)
{
    if(name != "") this->name = name;
    if(surname != "") this->surname = surname;
    if(description != "") this->description = description;

    QSqlQuery query;
    query.exec(this->getUpdateQuery());
}

QString SSBContact::getUpdateQuery()
{
    return "UPDATE contacts SET name = \'" +
            this->name + "\', surname = \'" +
            this->surname + "\', description = \'" +
            this->description + "\' WHERE id_contact = " +
            QVariant(this->id).toString() + ";";
}

QString SSBContact::getInsertQuery()
{
    return "INSERT INTO contacts VALUES (" + QVariant(this->id).toString() +
            ",\'" + this->name +
            "\',\'" + this->surname +
            "\',\'" + this->description +
            "\',\'" + this->owner + "\');";
}

QString SSBContact::getDeleteQuery()
{
    return "DELETE FROM contacts WHERE id_contact = " + QVariant(this->id).toString() + ";";
}

QString SSBContact::getPhonesQuery()
{
    return "SELECT * FROM phones WHERE id_contact = " + QVariant(this->id).toString() + ";";
}

QString SSBContact::getMailsQuery()
{
    return "SELECT * FROM emails WHERE id_contact = " + QVariant(this->id).toString() + ";";
}

QString SSBContact::getAddressesQuery()
{
    return "SELECT * FROM addresses WHERE id_contact = " + QVariant(this->id).toString() + ";";
}
