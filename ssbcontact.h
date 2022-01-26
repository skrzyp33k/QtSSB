#ifndef SSBCONTACT_H
#define SSBCONTACT_H

#include <QString>
#include <QVariant>
#include <QSqlQuery>

#include "ssbphone.h"
#include "ssbmail.h"
#include "ssbaddress.h"

class SSBContact
{
public:
    explicit SSBContact(int id_contact = -1, QString name = "", QString surname = "", QString description = "", QString owner = "");
    explicit SSBContact(QString name = "", QString surname = "", QString description = "", QString owner = "");

    void setValues(QString name, QString surname, QString description);

    int id;
    QString owner;

    QString name;
    QString surname;
    QString description;

    QVector<SSBPhone> phones;
    QVector<SSBMail> mails;
    QVector<SSBAddress> addresses;

    QString getUpdateQuery();
    QString getInsertQuery();
    QString getDeleteQuery();

    QString getPhonesQuery();
    QString getMailsQuery();
    QString getAddressesQuery();
};

#endif // SSBCONTACT_H
