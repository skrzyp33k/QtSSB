/**
 * @file useradddialog.h
 * @brief Plik nagłówkowy klasy UserAddDialog
 * @see UserAddDialog
 */
#ifndef USERADDDIALOG_H
#define USERADDDIALOG_H

#include <QDialog>

//! Główna przestrzeń nazw interfejsu użytkownika
namespace Ui {
class UserAddDialog;
}

class UserAddDialog : public QDialog
{
    Q_OBJECT

signals:
/**
 * @brief Sygnał emitowany przy zamknięciu okna
 */
    void closed();

public:
/**
 * @brief Konstruktor klasy UserAddDialog
 * @param parent Wskaźnik na QWidget rodzica
 * @see UserAddDialog
 * @see QWidget
 */
    explicit UserAddDialog(QWidget *parent = nullptr);

/**
 * @brief Destruktor klasy UserAddDialog
 * @see UserAddDialog
 */
    ~UserAddDialog();

/**
 * @brief Kontener QVector przechowujący wprowadzone dane
 * @see QVector
 * @see QString
 */
    QVector<QString> attrib;

/**
 * @brief Metoda uruchamiająca okno dialogowe klasy UserAddDialog
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
    Ui::UserAddDialog *ui;
};

#endif // USERADDDIALOG_H
