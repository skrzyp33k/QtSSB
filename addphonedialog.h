/**
 * @file addphonedialog.h
 * @brief Plik nagłówkowy klasy AddPhoneDialog
 * @see AddPhoneDialog
 */
#ifndef ADDPHONEDIALOG_H
#define ADDPHONEDIALOG_H

#include <QDialog>
#include <QIntValidator>

//! Główna przestrzeń nazw interfejsu użytkownika
namespace Ui {
class AddPhoneDialog;
}

class AddPhoneDialog : public QDialog
{
    Q_OBJECT

signals:
/**
 * @brief Sygnał emitowany przy zamknięciu okna
 */
    void closed();

public:
/**
 * @brief Konstruktor klasy AddPhoneDialog
 * @param parent Wskaźnik na QWidget rodzica
 * @see AddPhoneDialog
 * @see QWidget
 */
    explicit AddPhoneDialog(QWidget *parent = nullptr);

/**
 * @brief Destruktor klasy AddPhoneDialog
 * @see AddPhoneDialog
 */
    ~AddPhoneDialog();

/**
 * @brief QString przechowujący wprowadzoną daną
 * @see QString
 */
    QString attrib;

/**
 * @brief Metoda uruchamiająca okno dialogowe klasy AddPhoneDialog
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
    Ui::AddPhoneDialog *ui;
};

#endif // ADDPHONEDIALOG_H
