/**
 * @file addaddressdialog.h
 * @brief Plik nagłówkowy klasy AddAddressDialog
 * @see AddAddressDialog
 */
#ifndef ADDADDRESSDIALOG_H
#define ADDADDRESSDIALOG_H

#include <QDialog>
#include <QVector>

//! Główna przestrzeń nazw interfejsu użytkownika
namespace Ui {
class AddAddressDialog;
}

class AddAddressDialog : public QDialog
{
    Q_OBJECT

signals:
/**
 * @brief Sygnał emitowany przy zamknięciu okna
 */
    void closed();

public:
/**
 * @brief Konstruktor klasy AddAddressDialog
 * @param parent Wskaźnik na QWidget rodzica
 * @see AddAddressDialog
 * @see QWidget
 */
    explicit AddAddressDialog(QWidget *parent = nullptr);
/**
 * @brief Destruktor klasy AddAddressDialog
 * @see AddAddressDialog
 */
    ~AddAddressDialog();

/**
 * @brief Metoda uruchamiająca okno dialogowe klasy AddAddressDialog
 */
    void popUp();
    
/**
 * @brief Kontener QVector przechowujący wprowadzone dane
 * @see QVector
 * @see QString
 */
    QVector<QString> attrib;

private slots:
/**
 * @brief Slot obsługujący zdarzenie przyciśnięcie klawisza OK
 */
    void on_buttonBox_accepted();

private:
/**
 * @brief Wskaźnik wskazujący na interfejs graficzny
 */
    Ui::AddAddressDialog *ui;
};

#endif // ADDADDRESSDIALOG_H
