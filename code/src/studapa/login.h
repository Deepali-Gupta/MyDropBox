#ifndef LOGIN_H
#define LOGIN_H
#include <QtGui>
#include <QFile>
#include <QString>
#include <QMainWindow>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    int checkusername(QString user,QString pass);
    void addMail(QAbstractItemModel *model, const QString &subject,
                 const QString &sender, const QDateTime &date);
    QAbstractItemModel *createMailModel(QObject *parent);
    ~login();

private slots:
    void on_login_loginpg_clicked();

    void on_pushButton_clicked();

private:
    Ui::login *ui;
    char** username;
    char** password;
};

#endif // LOGIN_H
