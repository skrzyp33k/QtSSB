/**
 * @file mainwindow.cpp
 * @brief Plik źródłowy klasy MainWindow
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->serverConnectDialog = new ServerConnectDialog();

    this->userLoginDialog = new UserLoginDialog();

    this->userAddDialog = new UserAddDialog();

    this->userPassDialog = new UserPassDialog();

    this->contactAddDialog = new ContactAddDialog();

    this->addPhoneDialog = new AddPhoneDialog();

    this->addMailDialog = new AddMailDialog();

    this->addAddressDialog = new AddAddressDialog();

    this->database = QSqlDatabase::addDatabase("QMARIADB");

    this->_connected = false;

    this->_logged = false;

    this->_contactToggled = false;

    this->_contact = nullptr;

    this->_reloadUI();

    this->_contactListWidget = this->ui->contactListWidget;

    this->_phoneListWidget = this->ui->phoneListWidget;
    this->_mailListWidget = this->ui->mailListWidget;
    this->_addressListWidget = this->ui->addressListWidget;

    this->_nameLineEdit = this->ui->nameLineEdit;
    this->_surnameLineEdit = this->ui->surnameLineEdit;

    this->_descriptionEdit = this->ui->descriptionEdit;

    connect(this->_contactListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(on_contactList_itemClicked(QListWidgetItem*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_loadData()
{
    this->_ssbUsers.clear();
    this->_ssbContacts.clear();
    QSqlQuery query;
    //load users
    query.exec("SELECT * FROM users;");
    while(query.next())
    {
        _ssbUsers.push_back(SSBUser(
                                query.value(0).toString(),
                                query.value(1).toString()));
    }
    //load contacts
    query.exec("SELECT * FROM contacts;");
    while(query.next())
    {
        QSqlQuery contactAttribs;
        SSBContact *newContact = new SSBContact(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString());

        contactAttribs.exec(newContact->getPhonesQuery());
        while(contactAttribs.next())
        {
            newContact->phones.push_back(SSBPhone(
                                            contactAttribs.value(0).toInt(),
                                            contactAttribs.value(1).toInt(),
                                            contactAttribs.value(2).toString()));
        }
        contactAttribs.exec(newContact->getMailsQuery());
        while(contactAttribs.next())
        {
            newContact->mails.push_back(SSBMail(
                                            contactAttribs.value(0).toInt(),
                                            contactAttribs.value(1).toInt(),
                                            contactAttribs.value(2).toString()));
        }
        contactAttribs.exec(newContact->getAddressesQuery());
        while(contactAttribs.next())
        {
            newContact->addresses.push_back(SSBAddress(
                                            contactAttribs.value(0).toInt(),
                                            contactAttribs.value(1).toInt(),
                                            contactAttribs.value(2).toString(),
                                            contactAttribs.value(3).toString(),
                                            contactAttribs.value(4).toString(),
                                            contactAttribs.value(5).toString()));
        }
        _ssbContacts.push_back(newContact);
    }
    this->_reloadContactTable();
}

void MainWindow::_reloadUI()
{
    if(_connected)
    {
        this->ui->pushButton_Login->setEnabled(true);
        this->ui->pushButton_Disconnect->setEnabled(true);
        this->ui->pushButton_AddUser->setEnabled(true);
        this->ui->pushButton_Connect->setEnabled(false);
        if(_logged)
        {
            this->ui->pushButton_Login->setEnabled(false);
            this->ui->pushButton_Logout->setEnabled(true);
            this->ui->pushButton_ChangePassword->setEnabled(true);
            this->ui->pushButton_AddContact->setEnabled(true);
            if(_contactToggled)
            {
                this->ui->pushButton_AddPhone->setEnabled(true);
                this->ui->pushButton_AddMail->setEnabled(true);
                this->ui->pushButton_AddAddress->setEnabled(true);
                this->ui->pushButton_DeleteContact->setEnabled(true);
                this->ui->pushButton_SaveContact->setEnabled(true);
            }
            else
            {
                this->ui->pushButton_AddPhone->setEnabled(false);
                this->ui->pushButton_AddMail->setEnabled(false);
                this->ui->pushButton_AddAddress->setEnabled(false);
                this->ui->pushButton_DeleteContact->setEnabled(false);
                this->ui->pushButton_SaveContact->setEnabled(false);
            }
        }
        else
        {
            this->ui->pushButton_Login->setEnabled(true);
            this->ui->pushButton_Logout->setEnabled(false);
            this->ui->pushButton_ChangePassword->setEnabled(false);
            this->ui->pushButton_AddContact->setEnabled(false);
            this->ui->pushButton_DeleteContact->setEnabled(false);
            this->ui->pushButton_SaveContact->setEnabled(false);
            this->ui->pushButton_AddPhone->setEnabled(false);
            this->ui->pushButton_AddMail->setEnabled(false);
            this->ui->pushButton_AddAddress->setEnabled(false);
            this->ui->pushButton_DeletePhone->setEnabled(false);
            this->ui->pushButton_DeleteMail->setEnabled(false);
            this->ui->pushButton_DeleteAddress->setEnabled(false);
        }
    }
    else
    {
        this->ui->pushButton_Connect->setEnabled(true);
        this->ui->pushButton_Login->setEnabled(false);
        this->ui->pushButton_Disconnect->setEnabled(false);
        this->ui->pushButton_Logout->setEnabled(false);
        this->ui->pushButton_AddUser->setEnabled(false);
        this->ui->pushButton_ChangePassword->setEnabled(false);
        this->ui->pushButton_AddContact->setEnabled(false);
        this->ui->pushButton_DeleteContact->setEnabled(false);
        this->ui->pushButton_SaveContact->setEnabled(false);
        this->ui->pushButton_AddPhone->setEnabled(false);
        this->ui->pushButton_AddMail->setEnabled(false);
        this->ui->pushButton_AddAddress->setEnabled(false);
        this->ui->pushButton_DeletePhone->setEnabled(false);
        this->ui->pushButton_DeleteMail->setEnabled(false);
        this->ui->pushButton_DeleteAddress->setEnabled(false);
    }
}

void MainWindow::_clearTables()
{
    this->_phoneListWidget->clear();
    this->_mailListWidget->clear();
    this->_addressListWidget->clear();
    this->_nameLineEdit->clear();
    this->_surnameLineEdit->clear();
    this->_descriptionEdit->clear();
}

void MainWindow::_reloadContactTable()
{    
    this->_contactListWidget->clear();
    if(this->loggedUser != "")
    {
        for(auto it = _ssbContacts.begin(); it != _ssbContacts.end(); it++)
        {
            if((*it)->owner == this->loggedUser || this->loggedUser == "debug_admin")
            {
                QListWidgetItem *item = new QListWidgetItem();
                item->setData(0,(*it)->name + " " + (*it)->surname);
                item->setData(1,(*it)->id);
                this->_contactListWidget->addItem(item);
            }
        }
    }
}

void MainWindow::_loadDataLists()
{
    this->_clearTables();

    this->_nameLineEdit->setText(_contact->name);
    this->_surnameLineEdit->setText(_contact->surname);
    this->_descriptionEdit->document()->setPlainText(_contact->description);

    for(int i = 0; i < _contact->phones.size(); i++)
    {
        QListWidgetItem *item = new QListWidgetItem();
        item->setData(0, _contact->phones[i].phone);
        item->setData(1, _contact->phones[i].id);
        this->_phoneListWidget->addItem(item);
    }

    for(int i = 0; i < _contact->mails.size(); i++)
    {
        QListWidgetItem *item = new QListWidgetItem();
        item->setData(0, _contact->mails[i].mail);
        item->setData(1, _contact->mails[i].id);
        this->_mailListWidget->addItem(item);
    }

    for(int i = 0; i < _contact->addresses.size(); i++)
    {
        QListWidgetItem *item = new QListWidgetItem();
        QString addressString;
        addressString += _contact->addresses[i].fline + ", ";
        if(_contact->addresses[i].sline != "") addressString += _contact->addresses[i].sline + ", ";
        addressString += _contact->addresses[i].postal + ", " + _contact->addresses[i].city;
        item->setData(0, addressString);
        item->setData(1, _contact->addresses[i].id);
        this->_addressListWidget->addItem(item);
    }
}

void MainWindow::on_contactList_itemClicked(QListWidgetItem *item)
{
    for(auto it = _ssbContacts.begin(); it != _ssbContacts.end(); it++)
    {
        if((*it)->id == item->data(1).toInt())
        {
            _contact = *it;
            break;
        }
    }
    this->_contactToggled = true;
    this->_reloadUI();
    this->_loadDataLists();
}

void MainWindow::on_pushButton_Connect_clicked()
{

    serverConnectDialog->popUp();
    QEventLoop loop;
    connect(serverConnectDialog, SIGNAL(closed()), &loop, SLOT(quit()));
    loop.exec();

    database.setHostName(serverConnectDialog->attrib[0]);
    database.setDatabaseName(serverConnectDialog->attrib[1]);
    database.setUserName(serverConnectDialog->attrib[2]);
    database.setPassword(serverConnectDialog->attrib[3]);

    bool isConnected = database.open();

    if(isConnected)
    {
        this->ui->serverHostNameLabel->setText(serverConnectDialog->attrib[0]);
        _connected = true;
        this->_loadData();
        this->_reloadUI();
    }
    else
    {
        QMessageBox::critical(this, tr("QtSSB - ERROR"), tr("Cannot connect to database!"));
    }
}

void MainWindow::on_pushButton_Login_clicked()
{
    userLoginDialog->popUp();
    QEventLoop loop;
    connect(userLoginDialog, SIGNAL(closed()), &loop, SLOT(quit()));
    loop.exec();

    bool userExists = false;

    QString correctHash = "";

    int index = -1;

    foreach(SSBUser u, _ssbUsers)
    {
        index++;
        if(u.username == userLoginDialog->attrib[0])
        {
            userExists = true;
            correctHash = u.hash;
            break;
        }
    }
    if(userExists)
    {
        if(correctHash == SSBUser::ToMD5(userLoginDialog->attrib[1]))
        {
            this->_loadData();
            this->loggedUser = userLoginDialog->attrib[0];
            this->_logged = true;
            this->_loggedUserIndex = index;
            this->_reloadUI();
            this->ui->loggedUserLabel->setText(loggedUser);
            this->_reloadContactTable();
        }
        else
        {
            QMessageBox::critical(this, tr("QtSSB - ERROR"), tr("Wrong password!"));
        }
    }
    else
    {
        QMessageBox::critical(this, tr("QtSSB - ERROR"), tr("User does not exists!"));
    }
}

void MainWindow::on_pushButton_AddUser_clicked()
{
    userAddDialog->popUp();
    QEventLoop loop;
    connect(userAddDialog, SIGNAL(closed()), &loop, SLOT(quit()));
    loop.exec();

    QString username = userAddDialog->attrib[0];
    QString hash = userAddDialog->attrib[1];
    QString rhash = userAddDialog->attrib[2];

    bool userExists = false;

    foreach(SSBUser u, _ssbUsers)
    {
        if(u.username == username)
        {
            userExists = true;
            break;
        }
    }
    if(!userExists)
    {
        if(hash == rhash)
        {
            SSBUser newUser = SSBUser(username, SSBUser::ToMD5(hash));
            _ssbUsers.push_back(newUser);
            QSqlQuery query;
            query.exec(newUser.getInsertQuery());
            QMessageBox::information(this, tr("QtSSB - INFO"), tr("User added succesfully!"));
        }
        else
        {
            QMessageBox::critical(this, tr("QtSSB - ERROR"), tr("Passwords does not match!"));
        }
    }
    else
    {
        QMessageBox::critical(this, tr("QtSSB - ERROR"), tr("User exists!"));
    }
}

void MainWindow::on_pushButton_ChangePassword_clicked()
{
    userPassDialog->popUp();
    QEventLoop loop;
    connect(userPassDialog, SIGNAL(closed()), &loop, SLOT(quit()));
    loop.exec();

    QString actualHash = _ssbUsers[_loggedUserIndex].hash;
    QString oldHash = SSBUser::ToMD5(userPassDialog->attrib[0]);
    QString newHash = SSBUser::ToMD5(userPassDialog->attrib[1]);
    QString newRHash = SSBUser::ToMD5(userPassDialog->attrib[2]);

    if(actualHash == oldHash)
    {
        if(newHash == newRHash && newHash != "")
        {
            _ssbUsers[_loggedUserIndex].hash = newHash;
            QMessageBox::information(this, tr("QtSSB - INFO"), tr("Password changed succesfully!"));
            QSqlQuery query;
            query.exec(_ssbUsers[_loggedUserIndex].getUpdateQuery());
        }
        else
        {
            QMessageBox::critical(this, tr("QtSSB - ERROR"), tr("Passwords does not match!"));
        }
    }
    else
    {
        QMessageBox::critical(this, tr("QtSSB - ERROR"), tr("Wrong password!"));
    }
}

void MainWindow::on_pushButton_AddContact_clicked()
{
    contactAddDialog->popUp();
    QEventLoop loop;
    connect(contactAddDialog, SIGNAL(closed()), &loop, SLOT(quit()));
    loop.exec();

    if(contactAddDialog->attrib[0] != "" && contactAddDialog->attrib[1] != "")
    {
        SSBContact* newContact = new SSBContact(contactAddDialog->attrib[0],contactAddDialog->attrib[1],contactAddDialog->attrib[2], this->loggedUser);
        _ssbContacts.push_back(newContact);
        this->_loadData();
        this->_reloadContactTable();
    }
}

void MainWindow::on_pushButton_DeleteContact_clicked()
{
    QMessageBox *areYouSure = new QMessageBox(QMessageBox::Question, tr("QtSSB - CONFIRMATION"), tr("Are you sure you want to delete the contact?"), QMessageBox::Yes | QMessageBox::No);

    if(areYouSure->exec() == QMessageBox::Yes)
    {
        QSqlQuery query;
        query.exec(_contact->getDeleteQuery());
        for(auto it = _ssbContacts.begin(); it != _ssbContacts.end(); it++)
        {
            if((*it)->id == _contact->id)
            {
                _ssbContacts.erase(it);
                _contact = nullptr;
                break;
            }
        }
        this->_clearTables();
        this->_reloadContactTable();
        this->_reloadUI();
        this->ui->pushButton_DeleteContact->setEnabled(false);
        this->ui->pushButton_SaveContact->setEnabled(false);
        this->ui->pushButton_AddPhone->setEnabled(false);
        this->ui->pushButton_AddMail->setEnabled(false);
        this->ui->pushButton_AddAddress->setEnabled(false);
        this->ui->pushButton_DeletePhone->setEnabled(false);
        this->ui->pushButton_DeleteMail->setEnabled(false);
        this->ui->pushButton_DeleteAddress->setEnabled(false);
    }
}

void MainWindow::on_pushButton_SaveContact_clicked()
{
    _contact->setValues(this->ui->nameLineEdit->text(), this->ui->surnameLineEdit->text(), this->ui->descriptionEdit->document()->toPlainText());
    this->_reloadContactTable();
    this->_reloadUI();
}

void MainWindow::on_pushButton_Disconnect_clicked()
{
    QMessageBox *areYouSure = new QMessageBox(QMessageBox::Question, tr("QtSSB - CONFIRMATION"), tr("Are you sure to disconnect?"), QMessageBox::Yes | QMessageBox::No);

    if(areYouSure->exec() == QMessageBox::Yes)
    {
        this->_logged = false;
        this->loggedUser = "";
        this->ui->loggedUserLabel->setText(this->loggedUser);
        this->_reloadUI();
        this->_reloadContactTable();
        this->_clearTables();

        this->ui->serverHostNameLabel->setText("");
        this->database.close();
        this->_connected = false;
        this->_reloadUI();
    }
}

void MainWindow::on_pushButton_Logout_clicked()
{
    QMessageBox *areYouSure = new QMessageBox(QMessageBox::Question, tr("QtSSB - CONFIRMATION"), tr("Are you sure you want to log out?"), QMessageBox::Yes | QMessageBox::No);

    if(areYouSure->exec() == QMessageBox::Yes)
    {
        this->_logged = false;
        this->loggedUser = "";
        this->ui->loggedUserLabel->setText(this->loggedUser);
        this->_reloadUI();
        this->_reloadContactTable();
        this->_clearTables();
    }
}

void MainWindow::on_pushButton_AddPhone_clicked()
{
    addPhoneDialog->popUp();
    QEventLoop loop;
    connect(addPhoneDialog, SIGNAL(closed()), &loop, SLOT(quit()));
    loop.exec();

    if(addPhoneDialog->attrib != "")
    {
        _contact->phones.push_back(SSBPhone(_contact->id,addPhoneDialog->attrib));
        this->_loadDataLists();
    }
}

void MainWindow::on_pushButton_DeletePhone_clicked()
{
   int id = this->_phoneListWidget->selectedItems()[0]->data(1).toInt();
   for(auto it = _contact->phones.begin(); it != _contact->phones.end(); it++)
   {
       if(id == it->id)
       {
            QSqlQuery query;
            query.exec(it->getDeleteQuery());
            _contact->phones.erase(it);
            this->ui->pushButton_DeletePhone->setEnabled(false);
            this->ui->pushButton_DeleteMail->setEnabled(false);
            this->ui->pushButton_DeleteAddress->setEnabled(false);
            break;
       }
   }
   this->_loadDataLists();
}

void MainWindow::on_pushButton_AddMail_clicked()
{
    addMailDialog->popUp();
    QEventLoop loop;
    connect(addMailDialog, SIGNAL(closed()), &loop, SLOT(quit()));
    loop.exec();

    if(addMailDialog->attrib != "")
    {
        _contact->mails.push_back(SSBMail(_contact->id,addMailDialog->attrib));
        this->_loadDataLists();
    }
}

void MainWindow::on_pushButton_DeleteMail_clicked()
{
    int id = this->_mailListWidget->selectedItems()[0]->data(1).toInt();
    for(auto it = _contact->mails.begin(); it != _contact->mails.end(); it++)
    {
        if(id == it->id)
        {
             QSqlQuery query;
             query.exec(it->getDeleteQuery());
             _contact->mails.erase(it);
             this->ui->pushButton_DeletePhone->setEnabled(false);
             this->ui->pushButton_DeleteMail->setEnabled(false);
             this->ui->pushButton_DeleteAddress->setEnabled(false);
             break;
        }
    }
    this->_loadDataLists();
}

void MainWindow::on_pushButton_AddAddress_clicked()
{
    addAddressDialog->popUp();
    QEventLoop loop;
    connect(addAddressDialog, SIGNAL(closed()), &loop, SLOT(quit()));
    loop.exec();

    if(addAddressDialog->attrib[0] != "" && addAddressDialog->attrib[2] != "" && addAddressDialog->attrib[3] != "")
    {
        _contact->addresses.push_back(SSBAddress(_contact->id, addAddressDialog->attrib[0], addAddressDialog->attrib[1], addAddressDialog->attrib[2], addAddressDialog->attrib[3]));
        this->_loadDataLists();
    }
}

void MainWindow::on_pushButton_DeleteAddress_clicked()
{
    int id = this->_addressListWidget->selectedItems()[0]->data(1).toInt();
    for(auto it = _contact->addresses.begin(); it != _contact->addresses.end(); it++)
    {
        if(id == it->id)
        {
             QSqlQuery query;
             query.exec(it->getDeleteQuery());
             _contact->addresses.erase(it);
             this->ui->pushButton_DeletePhone->setEnabled(false);
             this->ui->pushButton_DeleteMail->setEnabled(false);
             this->ui->pushButton_DeleteAddress->setEnabled(false);
             break;
        }
    }
    this->_loadDataLists();
}

void MainWindow::on_phoneListWidget_itemClicked()
{
    this->ui->pushButton_DeletePhone->setEnabled(true);
}

void MainWindow::on_mailListWidget_itemClicked()
{
    this->ui->pushButton_DeleteMail->setEnabled(true);
}

void MainWindow::on_addressListWidget_itemClicked()
{
    this->ui->pushButton_DeleteAddress->setEnabled(true);
}
