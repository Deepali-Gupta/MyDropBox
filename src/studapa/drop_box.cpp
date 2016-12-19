#include "drop_box.h"
#include "ui_drop_box.h"
#include "login.h"
#include "ui_login.h"
#include "firstuser.h"
#include "ui_firstuser.h"
#include <string.h>
#include <string>

drop_box::drop_box(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::drop_box)
{

    ui->setupUi(this);
    QString path=QDir::currentPath();
    QString dp="/../studapa/hv-dropbox.jpg";

    path.append(dp);
    QFile file(path);
    QPixmap pix(path);
       ui->label_4->setPixmap(pix.scaled(ui->label_4->width(),ui->label_4->height(),Qt::KeepAspectRatio));
}

drop_box::~drop_box()
{
    delete ui;
}

void drop_box::on_login_clicked()
{

        lg = new login(this);
        lg->showMaximized();
        hide();
}

void drop_box::on_Register_clicked()
{
    fu = new firstuser(this);
    fu->showMaximized();
    hide();
}
