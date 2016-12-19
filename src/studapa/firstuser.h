#ifndef FIRSTUSER_H
#define FIRSTUSER_H
#include <QMainWindow>

namespace Ui {
class firstuser;
}

class firstuser : public QMainWindow
{
    Q_OBJECT

public:
    explicit firstuser(QWidget *parent = 0);
    bool check_username_availability();
    void* myFunc(void *arg);
    ~firstuser();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::firstuser *ui;
};

#endif // FIRSTUSER_H
