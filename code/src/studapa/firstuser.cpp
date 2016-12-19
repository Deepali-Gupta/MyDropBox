#include "firstuser.h"
#include "ui_firstuser.h"
#include "drop_box.h"
#include "ui_drop_box.h"

#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#define OUTPUT "./ssl-client 10.208.20.217 20001"
extern char output[100000];

firstuser::firstuser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::firstuser)
{
    ui->setupUi(this);
    QString path=QDir::currentPath();
    QString dp="/../studapa/hv-dropbox.jpg";

    path.append(dp);
    QFile file(path);
    QPixmap pix(path);
       ui->label_5->setPixmap(pix.scaled(ui->label_5->width(),ui->label_5->height(),Qt::KeepAspectRatio));
}


firstuser::~firstuser()
{
    delete ui;
}

void firstuser::on_pushButton_2_clicked()
{
    drop_box *home;
    home = new drop_box(this);
    home->showMaximized();
    hide();
}

bool firstuser::check_username_availability()
{   // Check username availability by taking input from newuser.txt.
    QString path=QDir::currentPath();
    QString dp="/reply.txt";
    path.append(dp);
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString msg;
    in>>msg;
    QString std="YES";
    int x = QString::compare(msg, std, Qt::CaseInsensitive);  // if strings are equal x should return 0
    if(!x)
    return true;
    else
        return false;

}


void firstuser::on_pushButton_clicked()
{
    /* Check if password and confirm password are non blank and same.
     * Store the username and password in temporary text file on client side.
     * Send the username password to server and check for availability of username.
     * If available add to database. If not error message
     */
    if (ui->lineEdit->text()==NULL || ui->lineEdit_3->text()==NULL)
    {
        ui->label_4->setText("Blank fields");
    }
    else
    {
        if (ui->lineEdit_2->text() != ui->lineEdit_3->text())
        {
            ui->label_4->setText("Passwords don't match");
        }

        else
        {
            QString path=QDir::currentPath();
            QString dp="/newuser.txt";
            path.append(dp);
            QFile file(path);   /*************************************** His home folder/file address here   */
            if (!file.open(QIODevice::WriteOnly)) {

                return;
            }
            QTextStream out(&file);

             // Here I am writing username and password in newuser.txt


            out <<'1'<<endl<< ui->lineEdit->text() << endl << ui->lineEdit_3->text();
            file.close();

            system("g++ -Wall -w -o ssl-client k_client.cpp -L/usr/lib -lssl -lcrypto");
            system(output);

            if (check_username_availability()) // Check username availability from database
            {
                // add username and password to database.
                // go back
                drop_box *home;
                home = new drop_box(this);
                home->showMaximized();
                hide();
            }
            else
            {
                ui->label_4->setText("Username not available");
            }

        }

    }
}
