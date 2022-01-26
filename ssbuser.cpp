/**
 * @file ssbuser.cpp
 * @brief Plik źródłowy klasy SSBUser
 * @see SSBUser
 */
#include "ssbuser.h"

SSBUser::SSBUser(QString username, QString hash)
{
    this->username = username;
    this->hash = hash;
}

QString SSBUser::getUpdateQuery()
{
    return "UPDATE users SET hash = \'" +
            this->hash + "\' WHERE username = \'" +
            this->username + "\';";
}

QString SSBUser::getInsertQuery()
{
    return "INSERT INTO users VALUES (\'" +
            this->username + "\',\'" +
            this->hash + "\');";
}

QString SSBUser::ToMD5(QString password)
{
    QCryptographicHash generator(QCryptographicHash::Md5);
    generator.addData(password.toStdString().c_str(), password.length());
    return QString(generator.result().toHex());
}
