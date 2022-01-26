/**
 * @file ssbmail.h
 * @brief Plik nagłówkowy klasy SSBMail
 * @see SSBMail
 */
#ifndef SSBMAIL_H
#define SSBMAIL_H

#include <QString>
#include <QVariant>
#include <QSqlQuery>

class SSBMail
{
public:
/**
 * @brief Konstruktor klasy SSBMail
 * @param id ID wpisu
 * @param id_contact ID kontaktu
 * @param mail Adres E-Mail 
 */
    explicit SSBMail(int id = -1, int id_contact = -1, QString mail = "");

/**
 * @brief Konstruktor klasy SSBMail
 * @param id_contact ID kontaktu
 * @param mail Adres E-Mail 
 */
    explicit SSBMail(int id_contact = -1, QString mail = "");

/**
 * @brief ID wpisu
 */
    int id;

/**
 * @brief ID kontaktu
 */
    int id_contact;

/**
 * @brief Adres E-Mail
 */
    QString mail;

/**
 * @brief Stworzenie kwerendy usuwającej
 * @return QString Kwerenda SQL
 */
    QString getDeleteQuery();
/**
 * @brief Stworzenie kwerendy wstawiającej
 * @return QString Kwerenda SQL
 */
    QString getInsertQuery();
};

#endif // SSBMAIL_H
