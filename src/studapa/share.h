#ifndef SHARE_H
#define SHARE_H

#include <QMainWindow>

namespace Ui {
class share;
}

class share : public QMainWindow
{
    Q_OBJECT

public:
    explicit share(QWidget *parent = 0);
    ~share();

private:
    Ui::share *ui;
};

#endif // SHARE_H
