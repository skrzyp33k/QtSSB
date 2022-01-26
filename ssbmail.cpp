/**
 * @file ssbmail.cpp
 * @brief Plik źródłowy klasy SSBMail
 * @see SSBMail
 */
#include "ssbmail.h"

SSBMail::SSBMail(int id, int id_contact, QString mail)
{
    this->id = id;
    this->id_contact = id_contact;
    this->mail = mail;
}

SSBMail::SSBMail(int id_contact, QString mail)
{
    this->id_contact = id_contact;
    this->mail = mail;

    QSqlQuery query;
    query.exec("SELECT MAX(id_email) FROM emails;");
    while(query.next())
    {
        if(query.value(0).toString() == "0") this->id = 1;
        else this->id = query.value(0).toInt() + 1;
    }

    query.exec(this->getInsertQuery());
}

QString SSBMail::getInsertQuery()
{
    return "INSERT INTO emails VALUES (" + QVariant(this->id).toString() +
            ",\'" +  QVariant(this->id_contact).toString() +
            "\',\'" + this->mail + "\');";
}

QString SSBMail::getDeleteQuery()
{
    return "DELETE FROM emails WHERE id_email = " + QVariant(this->id).toString() + ";";
}
