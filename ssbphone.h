#ifndef SSBPHONE_H
#define SSBPHONE_H

#include <QString>
#include <QVariant>
#include <QSqlQuery>

class SSBPhone
{
public:
    explicit SSBPhone(int id = -1, int id_contact = -1, QString phone = "");
    explicit SSBPhone(int id_contact = -1, QString phone = "");

    int id;
    int id_contact;

    QString phone;

    QString getInsertQuery();
    QString getDeleteQuery();
};

#endif // SSBPHONE_H
