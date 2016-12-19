#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include "drop_box.h"
#include "ui_drop_box.h"
#include "login.h"
#include "ui_login.h"
#include "afterlogin.h"
#include "ui_afterlogin.h"
#include <vector>
#include <QDebug>
extern char output[100000];

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QString path=QDir::currentPath();
    QString dp="/../studapa/hv-dropbox.jpg";

    path.append(dp);
    QFile file(path);
    QPixmap pix(path);
       ui->label_4->setPixmap(pix.scaled(ui->label_4->width(),ui->label_4->height(),Qt::KeepAspectRatio));
}


login::~login()
{
    delete ui;
}



int login::checkusername(QString user, QString pass)
{/*  ************************************************ Use this function to check if they are correct or not by comparing in a database. Return
   true or false.
    */
    QString path=QDir::currentPath();

    QString dp="/reply.txt";
    path.append(dp);
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString msg;
    in>>msg;
    QString std1="YES",std2="NO";
    if(QString::compare(msg, std1, Qt::CaseInsensitive)==0)
        return 1;  // if strings are equal x should return 1
    else if(QString::compare(msg, std2, Qt::CaseInsensitive)==0)
            return 2;  // if strings are not equal x should return 2
    else
        return 3; //if not registered

}


void login::on_login_loginpg_clicked()
{

    QString path=QDir::currentPath();

    QString dp="/newuser.txt";
    path.append(dp);
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {

        return;
    }
    QTextStream out(&file);

     // Here I am writing username and password in newuser.txt


    out <<'2'<<endl<< ui->user_name->text() << endl << ui->password->text();
    file.close();
    pthread_t tid1;
    system("g++ -Wall -w -o ssl-client k_client.cpp -L/usr/lib -lssl -lcrypto");
    system(output);


    if (checkusername(ui->user_name->text(),ui->password->text())==1)
    {

        ui->label_3->setText("Correct combination");

/********************************************************************Download all files of "ui->username->text()" into his home folder */
        QString path=QDir::currentPath();

        QString dp="/newuser.txt";
        path.append(dp);
        QFile file2(path);
        if (!file2.open(QIODevice::WriteOnly)) {

            return;
        }
        QTextStream out(&file2);

         // Here I am writing username and password in newuser.txt


        out <<'6'<<endl<<ui->user_name->text();
        file2.close();

        system("g++ -Wall -w -o ssl-client k_client.cpp -L/usr/lib -lssl -lcrypto");
        system(output);

        afterlogin *af;
        af = new afterlogin(ui->user_name->text(),this);
        af->showMaximized();
        hide();



}
    else if (checkusername(ui->user_name->text(),ui->password->text())==2)
    {
        ui->label_3->setText("Invalid Username or Password");
    }
    else
    {
        ui->label_3->setText("Not Registered");

    }

}

void login::on_pushButton_clicked()
{
    drop_box *home;
    home = new drop_box(this);
    home->showMaximized();
    hide();
}
