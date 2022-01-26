/**
 * @file serverconnectdialog.h
 * @brief Plik nagłówkowy klasy ServerConnectDialog
 * @see ServerConnectDialog
 */
#ifndef SERVERCONNECTDIALOG_H
#define SERVERCONNECTDIALOG_H

#include <QDialog>

//! Główna przestrzeń nazw interfejsu użytkownika
namespace Ui {
class ServerConnectDialog;
}

class ServerConnectDialog : public QDialog
{
    Q_OBJECT

signals:
/**
 * @brief Sygnał emitowany przy zamknięciu okna
 */
    void closed();

public:
/**
 * @brief Konstruktor klasy ServerConnectDialog
 * @param parent Wskaźnik na QWidget rodzica
 * @see ServerConnectDialog
 * @see QWidget
 */
    explicit ServerConnectDialog(QWidget *parent = nullptr);

/**
 * @brief Destruktor klasy ServerConnectDialog
 * @see ServerConectDialog
 */
    ~ServerConnectDialog();

/**
 * @brief Kontener QVector przechowujący wprowadzone dane
 * @see QVector
 * @see QString
 */
    QVector<QString> attrib;

/**
 * @brief Metoda uruchamiająca okno dialogowe klasy ServerConnectDialog
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
    Ui::ServerConnectDialog *ui;
};

#endif // SERVERCONNECTDIALOG_H
