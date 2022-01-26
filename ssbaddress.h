#ifndef SSBADDRESS_H
#define SSBADDRESS_H

#include <QString>
#include <QVariant>
#include <QSqlQuery>

class SSBAddress
{
public:
    explicit SSBAddress(int id = -1,int id_contact = -1, QString fline = "", QString sline = "", QString postal = "", QString city = "");
    explicit SSBAddress(int id_contact = -1, QString fline = "", QString sline = "", QString postal = "", QString city = "");

    int id;
    int id_contact;

    QString fline;
    QString sline;
    QString postal;
    QString city;

    QString getInsertQuery();
    QString getDeleteQuery();
};

#endif // SSBADDRESS_H
