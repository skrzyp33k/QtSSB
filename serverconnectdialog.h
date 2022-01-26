#ifndef SERVERCONNECTDIALOG_H
#define SERVERCONNECTDIALOG_H

#include <QDialog>


namespace Ui {
class ServerConnectDialog;
}

class ServerConnectDialog : public QDialog
{
    Q_OBJECT

signals:
    void closed();

public:
    explicit ServerConnectDialog(QWidget *parent = nullptr);
    ~ServerConnectDialog();

    QVector<QString> attrib;

    void popUp();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ServerConnectDialog *ui;
};

#endif // SERVERCONNECTDIALOG_H
