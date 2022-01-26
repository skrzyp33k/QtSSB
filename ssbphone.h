/**
 * @file ssbphone.h
 * @brief Plik nagłówkowy klasy SSBPhone
 * @see SSBPhone
 */
#ifndef SSBPHONE_H
#define SSBPHONE_H

#include <QString>
#include <QVariant>
#include <QSqlQuery>

class SSBPhone
{
public:
/**
 * @brief Konstruktor klasy SSBPhone
 * @param id ID wpisu
 * @param id_contact ID kontaktu
 * @param phone Numer telefonu
 */
    explicit SSBPhone(int id = -1, int id_contact = -1, QString phone = "");

    /**
 * @brief Konstruktor klasy SSBPhone
 * @param id_contact ID kontaktu
 * @param phone Numer telefonu
 */
    explicit SSBPhone(int id_contact = -1, QString phone = "");

/**
 * @brief ID wpisu
 */
    int id;

/**
 * @brief ID kontaktu
 */
    int id_contact;

/**
 * @brief Numer telefonu
 */
    QString phone;

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

#endif // SSBPHONE_H
