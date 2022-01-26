/**
 * @file ssbaddress.h
 * @brief Plik nagłówkowy klasy SSBAddress
 * @see SSBAddress
 */
#ifndef SSBADDRESS_H
#define SSBADDRESS_H

#include <QString>
#include <QVariant>
#include <QSqlQuery>

class SSBAddress
{
public:
/**
 * @brief Konstruktor klasy SSBAddress
 * @param id ID wpisu
 * @param id_contact ID kontaktu
 * @param fline Pierwsza linia adresu
 * @param sline Druga linia adresu
 * @param postal Kod pocztowy
 * @param city Miasto
 */
    explicit SSBAddress(int id = -1,int id_contact = -1, QString fline = "", QString sline = "", QString postal = "", QString city = "");

/**
 * @brief Konstruktor klasy SSBAddress
 * @param id_contact ID kontaktu
 * @param fline Pierwsza linia adresu
 * @param sline Druga linia adresu
 * @param postal Kod pocztowy
 * @param city Miasto
 */
    explicit SSBAddress(int id_contact = -1, QString fline = "", QString sline = "", QString postal = "", QString city = "");

/**
 * @brief ID wpisu
 */
    int id;

/**
 * @brief ID kontaktu
 */
    int id_contact;

/**
 * @brief Pierwsza linia adresu
 */
    QString fline;

/**
 * @brief Druga linia adresu
 */
    QString sline;

/**
 * @brief Kod pocztowy
 */    
    QString postal;

/**
 * @brief Miasto
 */
    QString city;

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

#endif // SSBADDRESS_H
