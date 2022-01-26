#ifndef ADDMAILDIALOG_H
#define ADDMAILDIALOG_H

#include <QDialog>

namespace Ui {
class AddMailDialog;
}

class AddMailDialog : public QDialog
{
    Q_OBJECT

signals:
    void closed();

public:
    explicit AddMailDialog(QWidget *parent = nullptr);
    ~AddMailDialog();

    void popUp();

    QString attrib;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddMailDialog *ui;
};

#endif // ADDMAILDIALOG_H
