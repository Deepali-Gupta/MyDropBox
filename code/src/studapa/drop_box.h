#ifndef DROP_BOX_H
#define DROP_BOX_H
#include "login.h"
#include "firstuser.h"
#include <QMainWindow>
#include "drop_box.h"
extern char exe[1024];
namespace Ui {
class drop_box;
}

class drop_box : public QMainWindow
{
    Q_OBJECT

public:
    explicit drop_box(QWidget *parent = 0);
    ~drop_box();


private slots:
    void on_login_clicked();

    void on_Register_clicked();

    void on_label_4_linkActivated(const QString &link);

private:
    Ui::drop_box *ui;
    login *lg;
    firstuser *fu;
};

#endif // DROP_BOX_H

//void drop_box::on_label_4_linkActivated(const QString &link)
//{

//}
