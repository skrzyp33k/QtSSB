#ifndef SSBMAIL_H
#define SSBMAIL_H

#include <QString>
#include <QVariant>
#include <QSqlQuery>

class SSBMail
{
public:
    explicit SSBMail(int id = -1, int id_contact = -1, QString phone = "");
    explicit SSBMail(int id_contact = -1, QString phone = "");

    int id;
    int id_contact;

    QString mail;

    QString getInsertQuery();
    QString getDeleteQuery();
};

#endif // SSBMAIL_H
