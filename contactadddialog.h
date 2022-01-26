/**
 * @file contactadddialog.h
 * @brief Plik nagłówkowy klasy ContactAddDialog
 * @see ContactAddDialog
 */
#ifndef CONTACTADDDIALOG_H
#define CONTACTADDDIALOG_H

#include <QDialog>

//! Główna przestrzeń nazw interfejsu użytkownika
namespace Ui {
class ContactAddDialog;
}

class ContactAddDialog : public QDialog
{
    Q_OBJECT
signals:
/**
 * @brief Sygnał emitowany przy zamknięciu okna
 */
    void closed();

public:
/**
 * @brief Konstruktor klasy ContactAddDialog
 * @param parent Wskaźnik na QWidget rodzica
 * @see ContactAddDialog
 * @see QWidget
 */
    explicit ContactAddDialog(QWidget *parent = nullptr);

/**
 * @brief Destruktor klasy ContactAddDialog
 * @see ContactAddDialog
 */
    ~ContactAddDialog();

/**
 * @brief Kontener QVector przechowujący wprowadzone dane
 * @see QVector
 * @see QString
 */
    QVector<QString> attrib;

/**
 * @brief Metoda uruchamiająca okno dialogowe klasy ContactAddDialog
 */
    void popUp();

private slots:
/**
 * @brief Slot obsługujący zdarzenie przyciśnięcie klawisza OK
 */
    void on_buttonBox_accepted();

private:
/**
 * @brief Wskaźnik wskazujący na interfejs graficzny
 */
    Ui::ContactAddDialog *ui;
};

#endif // CONTACTADDDIALOG_H
