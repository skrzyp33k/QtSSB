#ifndef SSBUSER_H
#define SSBUSER_H

#include <QString>
#include <QCryptographicHash>

class SSBUser
{
public:
    explicit SSBUser(QString username = "", QString hash = "");

    QString username;
    QString hash;

    QString getUpdateQuery();
    QString getInsertQuery();

    static QString ToMD5(QString password);

signals:

};

#endif // SSBUSER_H
