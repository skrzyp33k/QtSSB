/**
 * @file userpassdialog.h
 * @brief Plik nagłówkowy klasy UserPassDialog
 * @see UserPassDialog
 */
#ifndef USERPASSDIALOG_H
#define USERPASSDIALOG_H

#include <QDialog>

//! Główna przestrzeń nazw interfejsu użytkownika
namespace Ui {
class UserPassDialog;
}

class UserPassDialog : public QDialog
{
    Q_OBJECT

signals:
/**
 * @brief Sygnał emitowany przy zamknięciu okna
 */
    void closed();

public:
/**
 * @brief Konstruktor klasy UserPassDialog
 * @param parent Wskaźnik na QWidget rodzica
 * @see UserPassDialog
 * @see QWidget
 */
    explicit UserPassDialog(QWidget *parent = nullptr);

/**
 * @brief Destruktor klasy UserPassDialog
 * @see UserPassDialog
 */
    ~UserPassDialog();

/**
 * @brief Kontener QVector przechowujący wprowadzone dane
 * @see QVector
 * @see QString
 */
    QVector<QString> attrib;

/**
 * @brief Metoda uruchamiająca okno dialogowe klasy UserPassDialog
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
    Ui::UserPassDialog *ui;
};

#endif // USERPASSDIALOG_H
