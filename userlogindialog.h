/**
 * @file userlogindialog.h
 * @brief Plik nagłówkowy klasy UserLoginDialog
 * @see UserLoginDialog
 */
#ifndef USERLOGINDIALOG_H
#define USERLOGINDIALOG_H

#include <QDialog>

//! Główna przestrzeń nazw interfejsu użytkownika
namespace Ui {
class UserLoginDialog;
}

class UserLoginDialog : public QDialog
{
    Q_OBJECT

signals:
/**
 * @brief Sygnał emitowany przy zamknięciu okna
 */
    void closed();

public:
/**
 * @brief Konstruktor klasy UserLoginDialog
 * @param parent Wskaźnik na QWidget rodzica
 * @see UserLoginDialog
 * @see QWidget
 */
    explicit UserLoginDialog(QWidget *parent = nullptr);

/**
 * @brief Destruktor klasy UserLoginDialog
 * @see UserLoginDialog
 */
    ~UserLoginDialog();

/**
 * @brief Kontener QVector przechowujący wprowadzone dane
 * @see QVector
 * @see QString
 */
    QVector<QString> attrib;

/**
 * @brief Metoda uruchamiająca okno dialogowe klasy UserLoginDialog
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
    Ui::UserLoginDialog *ui;
};

#endif // USERLOGINDIALOG_H
