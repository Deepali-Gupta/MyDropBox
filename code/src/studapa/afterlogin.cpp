#include "afterlogin.h"
#include "ui_afterlogin.h"
#include "share.h"
#include "ui_share.h"
#include "drop_box.h"
#include "ui_drop_box.h"
#include "versions.h"
#include "ui_versions.h"
#include <QtGui>
#include <QFileSystemModel>
#include <QDirModel>
#include <QTreeView>
#include <QListView>
 #include <QAbstractItemModel>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
extern char output[100000];


afterlogin::afterlogin(QString username1,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::afterlogin)
{
    username = username1;

    ui->setupUi(this);
    QString path2=QDir::currentPath();
    QString dp2="/../studapa/hv-dropbox.jpg";

    path2.append(dp2);
    QFile file(path2);
    QPixmap pix(path2);
       ui->label_3->setPixmap(pix.scaled(ui->label_3->width(),ui->label_3->height(),Qt::KeepAspectRatio));
    model = new QFileSystemModel(this);
    QString path=QDir::currentPath();

    QString dp="/MyDropBox/";
    path.append(dp);
    path.append(username);
    dp="/";
    path.append(dp);
    model->setRootPath(path);                     /*******************************  Set home directory of "username" home directory here*/

    ui->treeView->setModel(model);

    ui->treeView->setRootIndex(model->index(path));        /*******************************  Set his home directory here*/

    QString filepath = model->fileName(model->index(path));   /******************** and here */
    ui->label->setText(filepath);
    ui->comboBox->hide();
    ui->lineEdit->hide();
    ui->share_2->hide();
    ui->comboBox_2->hide();
}


afterlogin::~afterlogin()
{
    delete ui;
}


void afterlogin::selectedFile()
{
    file_path = model->filePath(ui->treeView->selectionModel()->currentIndex());/***************************Path of Selected file (All operations to be done on it)*/
    file_name = model->fileName(ui->treeView->selectionModel()->currentIndex());/************************* Name of selected file */
    ui->label->setText(file_name);

}


void afterlogin::on_treeView_activated(const QModelIndex &index)
{
}

void afterlogin::on_select_clicked()
{
    selectedFile();
}



void afterlogin::on_upload_clicked()
{
    QString path=QDir::currentPath();
    QString dp="/newuser.txt";
    path.append(dp);
    QFile file(path);  /*************************************** His home folder/file address here   */
    if (!file.open(QIODevice::WriteOnly)) {

        return;
    }
    QTextStream out(&file);

     // Here I am writing username and password in newuser.txt


    out <<'3'<<endl<<username<<endl<< file_path;
    file.close();
    system("g++ -Wall -w -o ssl-client k_client.cpp -L/usr/lib -lssl -lcrypto");
    system(output);


    /*****************************************Upload file with path in file_path to the server*/
    path=QDir::currentPath();
    dp="/reply.txt";
    path.append(dp);
    QFile fin(path);  /*************************************** His home folder/file address here   */
    fin.open(QIODevice::ReadOnly);
    QTextStream in(&fin);
    QString msg;
    in>>msg;
    fin.close();

    QString std="YES";
    int x = QString::compare(msg, std, Qt::CaseInsensitive);  // if strings are equal x should return 0
    if(x==0)
        ui->label->setText("Upload Successful");
    else
        ui->label->setText("Upload Failed");




}

void afterlogin::on_upload_all_clicked()
{
    QString path=QDir::currentPath();

    QString dp="/newuser.txt";
    path.append(dp);
    QFile file(path);  /*************************************** His home folder/file address here   */
    if (!file.open(QIODevice::WriteOnly)) {

        return;
    }
    QTextStream out(&file);

     // Here I am writing username and password in newuser.txt


    out <<'4'<<endl<<username;
    file.close();
    system("g++ -Wall -w -o ssl-client k_client.cpp -L/usr/lib -lssl -lcrypto");
    system(output);

    /**************************************** Upload all files of the user to the server */
    path=QDir::currentPath();
    dp="/reply.txt";
    path.append(dp);
    QFile fin(path);  /*************************************** His home folder/file address here   */
    fin.open(QIODevice::ReadOnly);
    QTextStream in(&fin);
    QString msg;
    in>>msg;
    fin.close();

    QString std="YES";
    int x = QString::compare(msg, std, Qt::CaseInsensitive);  // if strings are equal x should return 0
    if(x==0)
        ui->label->setText("Upload All Successful");
    else
        ui->label->setText("Upload All Failed");

}

void afterlogin::on_signout_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Sign out", "Do you want to upload your files",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        qDebug() << "Yes was clicked";
        /************************************Upload all files of the user to the server */
        QString path=QDir::currentPath();

        QString dp="/newuser.txt";
        path.append(dp);
        QFile file(path);  /*************************************** His home folder/file address here   */
        if (!file.open(QIODevice::WriteOnly)) {

            return;
        }
        QTextStream out(&file);

         // Here I am writing username and password in newuser.txt


        out <<'4'<<endl<<username;
        file.close();
        system("g++ -Wall -w -o ssl-client k_client.cpp -L/usr/lib -lssl -lcrypto");
        system(output);

        drop_box *af;
        af = new drop_box(this);
        af->showMaximized();
        hide();


      } else {
        qDebug() << "Yes was *not* clicked";
        drop_box *af;
        af = new drop_box(this);
        af->showMaximized();
        hide();
      }
}

void afterlogin::on_share_clicked()
{
    ui->comboBox->show();
    ui->comboBox_2->show();
    ui->lineEdit->show();
    ui->share_2->show();

    /****************************************** Transfer his friendlist from server to his home folder.*/
    QFile file("/home/bee/Desktop/shubham/studapa/friendlist.txt");   /*************************************** His home folder/file address here*/
    if(!file.open(QIODevice::ReadOnly)) {
    }

    ui->comboBox->addItem("");
    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();

        ui->comboBox->addItem(line);
    }

    file.close();

    ui->comboBox_2->addItem("Read Only");
    ui->comboBox_2->addItem("Read and Write");




}

void afterlogin::on_share_2_clicked()
{
    QString sharewith;
    int read_write = 0;                                              // 0 if read, 1 if write
    if (ui->comboBox->currentText()=="" && ui->lineEdit->text()=="")
    {
        ui->label->setText("Please choose a user");
    }
    else
    {
    if (ui->comboBox->currentText()=="")
    {
        sharewith = ui->lineEdit->text();
    }
    else
        sharewith = ui->comboBox->currentText();
    if (ui->comboBox_2->currentText()=="Read and Write")
         read_write = 1;
    /****************************************** Check for presence of user "sharewith" */
    /* if present then */
    /******************************************share "file_name" with "sharewith" and permission "read_write" */
    /* else do nothing */
        // qDebug()<<file_path<<sharewith<<read_write<<endl;


    }
    ui->comboBox->hide();
    ui->lineEdit->hide();
    ui->share_2->hide();
    ui->comboBox_2->hide();
}

void afterlogin::on_prev_clicked()
{
    /********************************************* Check if selected file versions are present on server side (selected file may be a folder
     * In that case return false)
     * if false : do nothing
     * if true : do the following
     */
    versions *vs;
    vs = new versions(username,file_name,this);
    vs->showMaximized();
    hide();


}

void afterlogin::on_down_clicked()
{
    QString path=QDir::currentPath();

    QString dp="/newuser.txt";
    path.append(dp);
    QFile file(path);  /*************************************** His home folder/file address here   */
    if (!file.open(QIODevice::WriteOnly)) {

        return;
    }
    QTextStream out(&file);

     // Here I am writing username and password in newuser.txt


    out <<'5'<<endl<<username<<endl<< file_path;
    file.close();
    system("g++ -Wall -w -o ssl-client k_client.cpp -L/usr/lib -lssl -lcrypto");
    system(output);

    /*****************************************Upload file with path in file_path to the server*/
    path=QDir::currentPath();

    dp="/reply.txt";
    path.append(dp);
    QFile fin(path);  /*************************************** His home folder/file address here   */
    fin.open(QIODevice::ReadOnly);
    QTextStream in(&fin);
    QString msg;
    in>>msg;
    fin.close();

    QString std="YES";
    int x = QString::compare(msg, std, Qt::CaseInsensitive);  // if strings are equal x should return 0
    if(x==0)
        ui->label->setText("Download Successful");
    else
        ui->label->setText("Download Failed");




}
