#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    void initUI();
    ~LoginDialog();

private slots:
    void on_loginBtn_clicked();

private:
    Ui::LoginDialog *ui;
    QWidget *titleWidget;
    QPushButton *miniBut;
    QPushButton *closeBut;
};

#endif // LOGINDIALOG_H
