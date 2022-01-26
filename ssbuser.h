/**
 * @file ssbuser.h
 * @brief Plik nagłówkowy klasy SSBUser
 * @see SSBUser
 */
#ifndef SSBUSER_H
#define SSBUSER_H

#include <QString>
#include <QCryptographicHash>

class SSBUser
{
public:
/**
 * @brief Konstruktor klasy SSBUser
 * @param username Nazwa użytkownika
 * @param hash Suma kontrolna z hasła
 * @see QString
 */
    explicit SSBUser(QString username = "", QString hash = "");
/**
 * @brief Nazwa użytkownika
 */
    QString username;

/**
 * @brief Suma kontrolna z hasła
 */
    QString hash;

/**
 * @brief Stworzenie kwerendy aktualizującej
 * @return QString Kwerenda SQL
 */
    QString getUpdateQuery();
/**
 * @brief Stworzenie kwerendy wstawiającej
 * @return QString Kwerenda SQL
 */
    QString getInsertQuery();

/**
 * @brief Wyliczenie sumy kontrolnej MD5
 * @param password Hasło z którego będzie wyliczona suma kontrolna
 * @return QString Suma kontrolna MD5
 */
    static QString ToMD5(QString password);
};

#endif // SSBUSER_H
