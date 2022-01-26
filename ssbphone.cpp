/**
 * @file ssbphone.cpp
 * @brief Plik źródłowy klasy SSBPhone
 * @see SSBPhone
 */
#include "ssbphone.h"

SSBPhone::SSBPhone(int id, int id_contact, QString phone)
{
    this->id = id;
    this->id_contact = id_contact;
    this->phone = phone;
}

SSBPhone::SSBPhone(int id_contact, QString phone)
{
    this->id_contact = id_contact;
    this->phone = phone;

    QSqlQuery query;
    query.exec("SELECT MAX(id_phone) FROM phones;");
    while(query.next())
    {
        if(query.value(0).toString() == "0") this->id = 1;
        else this->id = query.value(0).toInt() + 1;
    }

    query.exec(this->getInsertQuery());
}

QString SSBPhone::getInsertQuery()
{
    return "INSERT INTO phones VALUES (" + QVariant(this->id).toString() +
            ",\'" +  QVariant(this->id_contact).toString() +
            "\',\'" + this->phone + "\');";
}

QString SSBPhone::getDeleteQuery()
{
    return "DELETE FROM phones WHERE id_phone = " + QVariant(this->id).toString() + ";";
}
