#include "versions.h"
#include "ui_versions.h"

#include "afterlogin.h"
#include "ui_afterlogin.h"
#include <QTableWidget>
versions::versions(QString username,QString filename,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::versions)
{
    ui->setupUi(this);
    file = filename;
    user = username;

    ui->tableWidget->setRowCount(10);           /***************** Change no of rows if needed */
    ui->tableWidget->setColumnCount(2);
    for (int r = 0;r<10;r++)                     /********************* Corresponds to 10 versions (Each row corresponds to a version) Change if needed*/
    {
        QTableWidgetItem *item = new QTableWidgetItem("Version1");  /*********************Somehow enter each version name of file "file" here */
        ui->comboBox->addItem("Version1");

         ui->tableWidget->setItem(r,0,item);
        QTableWidgetItem *item2 = new QTableWidgetItem("LastModified version1");  /*********************Somehow enter last modified of version r */

         ui->tableWidget->setItem(r,1,item2);
    }



}

versions::~versions()
{
    delete ui;
}

void versions::on_pushButton_2_clicked()
{
    afterlogin *af;
    af = new afterlogin(user,this);
    af->showMaximized();
    hide();
}

void versions::on_pushButton_clicked()
{
    QString version_name = ui->comboBox->currentText(); /***********************Download the version with name "version_name" of the file "file" here , somehow */

}

void versions::on_tableWidget_activated(const QModelIndex &index)
{

}
