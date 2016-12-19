#ifndef AFTERLOGIN_H
#define AFTERLOGIN_H
#include <QString>
#include <QMainWindow>
#include <QFileSystemModel>
namespace Ui {
class afterlogin;
}

class afterlogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit afterlogin(QString username1,QWidget *parent = 0);
    void selectedFile();
    QString file_path;
    QString file_name;
    QString username;
    ~afterlogin();

private slots:

    void on_treeView_activated(const QModelIndex &index);

    void on_select_clicked();


    void on_upload_clicked();

    void on_upload_all_clicked();

    void on_signout_clicked();

    void on_share_clicked();

    void on_share_2_clicked();

    void on_prev_clicked();

    void on_down_clicked();


private:
    Ui::afterlogin *ui;
    QFileSystemModel *model;

};

#endif // AFTERLOGIN_H
