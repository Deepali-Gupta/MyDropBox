#ifndef VERSIONS_H
#define VERSIONS_H
#include <QString>
#include <QMainWindow>
#include <QString>
namespace Ui {
class versions;
}

class versions : public QMainWindow
{
    Q_OBJECT

public:
    explicit versions(QString username,QString filename,QWidget *parent = 0);
    QString user;
    QString file;
    ~versions();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_tableWidget_activated(const QModelIndex &index);

private:
    Ui::versions *ui;
};

#endif // VERSIONS_H
