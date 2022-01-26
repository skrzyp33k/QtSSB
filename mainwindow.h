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

#include "ssbcontact.h"

#include "ssbuser.h"

#include "addphonedialog.h"

#include "addmaildialog.h"

#include "addaddressdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ServerConnectDialog *serverConnectDialog;

    UserLoginDialog *userLoginDialog;

    UserAddDialog *userAddDialog;

    UserPassDialog *userPassDialog;

    ContactAddDialog *contactAddDialog;

    AddPhoneDialog *addPhoneDialog;

    AddMailDialog *addMailDialog;

    AddAddressDialog *addAddressDialog;

    QSqlDatabase database;

    QString loggedUser;

private slots:

    void on_pushButton_Connect_clicked();

    void on_pushButton_Login_clicked();

    void on_pushButton_AddUser_clicked();

    void on_pushButton_ChangePassword_clicked();

    void on_pushButton_AddContact_clicked();

    void on_pushButton_Disconnect_clicked();

    void on_pushButton_Logout_clicked();

    void on_contactList_itemClicked(QListWidgetItem*);

    void on_pushButton_DeleteContact_clicked();

    void on_pushButton_SaveContact_clicked();

    void on_pushButton_AddPhone_clicked();

    void on_pushButton_DeletePhone_clicked();

    void on_pushButton_AddMail_clicked();

    void on_pushButton_DeleteMail_clicked();

    void on_pushButton_AddAddress_clicked();

    void on_pushButton_DeleteAddress_clicked();

    void on_phoneListWidget_itemClicked();

    void on_mailListWidget_itemClicked();

    void on_addressListWidget_itemClicked();

private:
    Ui::MainWindow *ui;

    QListWidget *_contactListWidget;

    QListWidget *_phoneListWidget;
    QListWidget *_mailListWidget;
    QListWidget *_addressListWidget;

    QLineEdit *_nameLineEdit;
    QLineEdit *_surnameLineEdit;

    QPlainTextEdit *_descriptionEdit;

    QVector<SSBUser> _ssbUsers;

    QVector<SSBContact*> _ssbContacts;

    SSBContact *_contact;

    QVector<QString> _pendingQueries;

    int _loggedUserIndex;

    void _loadData();

    void _reloadUI();

    void _clearTables();

    void _reloadContactTable();

    void _loadDataLists();

    bool _connected;

    bool _logged;

    bool _contactToggled;
};
#endif // MAINWINDOW_H
