/**
 * @file ssbcontact.h
 * @brief Plik nagłówkowy klasy SSBContact
 * @see SSBContact
 */
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

/**
 * @brief ID kopntaktu
 */
    int id;

/**
 * @brief Właściciel kontaktu
 */
    QString owner;

/**
 * @brief Imię
 */
    QString name;

/**
 * @brief Nazwisko
 */
    QString surname;

/**
 * @brief Opis
 */
    QString description;


/**
 * @brief Kontener QVector zawierający numery telefonów
 * @see QVector
 * @see SSBPhone
 */
    QVector<SSBPhone> phones;

/**
 * @brief Kontener QVecotr zawierający adresy e-mail
 * @see QVector
 * @see SSBMail
 */
    QVector<SSBMail> mails;

/**
 * @brief Kontener QVector zawierający adresy
 * @see QVector
 * @see SSBAddress
 */
    QVector<SSBAddress> addresses;

/**
 * @brief Stworzenie kwerendy aktualizującej
 * @return QString Kwerenda SQL
 */
    QString getUpdateQuery();

/**
 * @brief Stworzenie kwerendy dodającej
 * @return QString Kwerenda SQL
 */
    QString getInsertQuery();

/**
 * @brief Stworzenie kwerendy usuwajacej
 * @return QString Kwerenda SQL
 */
    QString getDeleteQuery();

/**
 * @brief Stworzenie kwerendy pobierającej telefony
 * @return QString Kwerenda SQL
 */
    QString getPhonesQuery();

    /**
 * @brief Stworzenie kwerendy pobierającej adresy email
 * @return QString Kwerenda SQL
 */
    QString getMailsQuery();

    /**
 * @brief Stworzenie kwerendy pobierającej adresy
 * @return QString Kwerenda SQL
 */
    QString getAddressesQuery();
};

#endif // SSBCONTACT_H
