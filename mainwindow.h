/**
 * @file mainwindow.h
 * @brief Plik nagłówkowy klasy MainWindow
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QString>
#include <QMessageBox>
#include <QListWidget>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QLocale>
#include <QPlainTextEdit>
#include <QLineEdit>

#include "serverconnectdialog.h"

#include "userlogindialog.h"
#include "useradddialog.h"
#include "userpassdialog.h"

#include "contactadddialog.h"

#include "addphonedialog.h"
#include "addmaildialog.h"
#include "addaddressdialog.h"

#include "ssbcontact.h"
#include "ssbuser.h"

QT_BEGIN_NAMESPACE
//! Główna przestrzeń nazw interfejsu użytkownika
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
/**
 * @brief Konstruktor klasy MainWindow
 * @param parent Wskaźnik na QWidget rodzica
 * @see MainWindow
 * @see QWidget
 */
    MainWindow(QWidget *parent = nullptr);

/**
 * @brief Destruktor klasy MainWindow
 */
    ~MainWindow();

    ServerConnectDialog *serverConnectDialog; //< Wskaźnik na obiekt klasy ServerConnectDialog

    UserLoginDialog *userLoginDialog; //< Wskaźnik na obiekt klasy UserLoginDialog

    UserAddDialog *userAddDialog; //< Wskaźnik na obiekt klasy UserAddDialog

    UserPassDialog *userPassDialog; //< Wskaźnik na obiekt klasy UserPassDialog

    ContactAddDialog *contactAddDialog; //< Wskaźnik na obiekt klasy ContactAddDialog

    AddPhoneDialog *addPhoneDialog; //< Wskaźnik na obiekt klasy AddPhoneDialog

    AddMailDialog *addMailDialog; //<Wskaźnik na obiekt klasy AddMailDialog

    AddAddressDialog *addAddressDialog; //< Wskaźnik na obiekt klasy AddAddressDialog

    QSqlDatabase database; //< Zmienna przechowująca połączenie z bazą danych

    QString loggedUser; //< Zmienna przechowująca nazwę aktualnie zalogowanego użytkownika

private slots:

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika Connect
 */
    void on_pushButton_Connect_clicked();

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika Login
 */
    void on_pushButton_Login_clicked();

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika AddUser
 */
    void on_pushButton_AddUser_clicked();

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika ChangePassword
 */
    void on_pushButton_ChangePassword_clicked();

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika AddContact
 */
    void on_pushButton_AddContact_clicked();

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika Disconnect
 */
    void on_pushButton_Disconnect_clicked();

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika Logout
 */
    void on_pushButton_Logout_clicked();

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika DeleteContact
 */
    void on_pushButton_DeleteContact_clicked();

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika SaveContact
 */
    void on_pushButton_SaveContact_clicked();

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika AddPhone
 */
    void on_pushButton_AddPhone_clicked();

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika DeletePhone
 */
    void on_pushButton_DeletePhone_clicked();

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika AddMail
 */
    void on_pushButton_AddMail_clicked();

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika DeleteMail
 */
    void on_pushButton_DeleteMail_clicked();

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika AddAddress
 */
    void on_pushButton_AddAddress_clicked();

/**
 * @brief Slot obsługujący zdarzenie kliknięcia guzika DeleteAddress
 */
    void on_pushButton_DeleteAddress_clicked();

/**
 * @brief Slot obsługujący zdarzenie wybrania elementu z listy telefonów
 */
    void on_phoneListWidget_itemClicked();

/**
 * @brief Slot obsługujący zdarzenie wybrania elementu z listy e-maili
 */
    void on_mailListWidget_itemClicked();

/**
 * @brief Slot obsługujący zdarzenie wybrania elementu z listy adresów
 */
    void on_addressListWidget_itemClicked();
    
/**
 * @brief Slot obsługujący zdarzenie wybrania elementu z listy kontaktów
 */
    void on_contactList_itemClicked(QListWidgetItem*);

private:
    Ui::MainWindow *ui; //< Wskaźnik na interfejs użytkownika

    QListWidget *_contactListWidget; //< Wskaźnik na listę z kontaktami

    QListWidget *_phoneListWidget; //< Wskaźnik na listę z telefonami
    QListWidget *_mailListWidget; //< Wskaźnik na listę z e-mailami
    QListWidget *_addressListWidget; //< Wskaźnik na listę z adresami

    QLineEdit *_nameLineEdit; //< Wskaźnik na pole tekstowe imienia
    QLineEdit *_surnameLineEdit; //< Wskaźnik na pole tekstowe nazwiska

    QPlainTextEdit *_descriptionEdit; //< Wskaźnik na pole tekstowe opisu

    QVector<SSBUser> _ssbUsers; //< Kontener QVector zawierający dane o użytkownikach

    QVector<SSBContact*> _ssbContacts; //< Kontener QVector zawierający wskaźniki na dane o kontaktach

    SSBContact *_contact; //< Wskaźnik na aktualnie edytowany kontakt

    int _loggedUserIndex; //< Indeks aktualnie zalogowanego użytkownika

    void _loadData(); //< Metoda ładująca dane z bazy

    void _reloadUI(); //< Metoda odpowiedzialna za odświeżenie wyglądu interfejsu

    void _clearTables(); //< Metoda odpowiedzialna za wyczyszczenie list z danymi

    void _reloadContactTable(); //< Metoda odpowiedzialna za przeładowanie listy z kontami

    void _loadDataLists(); //< Metoda odpowiedzialna za załadowanie szczegółów kontaktu do poszczególnych list

    bool _connected; //< Flaga przechowująca informacje o stanie połączenia z serwerem

    bool _logged; //< Flaga przechowująca informacje o statusie zalogowania użytkownika

    bool _contactToggled; //< Flaga przechowująca informacje o wyborze kontaktu
};
#endif // MAINWINDOW_H
