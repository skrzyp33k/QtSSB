/**
 * @file addmaildialog.h
 * @brief Plik nagłówkowy klasy AddMailDialog
 * @see AddMailDialog
 */

#ifndef ADDMAILDIALOG_H
#define ADDMAILDIALOG_H

#include <QDialog>

//! Główna przestrzeń nazw interfejsu użytkownika
namespace Ui {
class AddMailDialog;
}

class AddMailDialog : public QDialog
{
    Q_OBJECT

signals:
/**
 * @brief Sygnał emitowany przy zamknięciu okna
 */
    void closed();

public:
/**
 * @brief Konstruktor klasy AddMailDialog
 * @param parent Wskaźnik na QWidget rodzica
 * @see AddMailDialog
 * @see QWidget
 */
    explicit AddMailDialog(QWidget *parent = nullptr);

/**
 * @brief Destruktor klasy AddMailDialog
 * @see AddMailDialog
 */
    ~AddMailDialog();

/**
 * @brief Metoda uruchamiająca okno dialogowe klasy AddMailDialog
 */
    void popUp();

/**
 * @brief QString przechowujący wprowadzoną daną
 * @see QString
 */
    QString attrib;

private slots:
/**
 * @brief Slot obsługujący zdarzenie przyciśnięcie klawisza OK
 */
    void on_buttonBox_accepted();

private:
/**
 * @brief Wskaźnik wskazujący na interfejs graficzny
 */
    Ui::AddMailDialog *ui;
};

#endif // ADDMAILDIALOG_H
