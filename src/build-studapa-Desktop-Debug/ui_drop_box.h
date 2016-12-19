/********************************************************************************
** Form generated from reading UI file 'drop_box.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DROP_BOX_H
#define UI_DROP_BOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_drop_box
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *login;
    QPushButton *Register;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *drop_box)
    {
        if (drop_box->objectName().isEmpty())
            drop_box->setObjectName(QStringLiteral("drop_box"));
        drop_box->resize(800, 600);
        centralwidget = new QWidget(drop_box);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(297, 80, 210, 22));
        label->setStyleSheet(QLatin1String("\n"
"font: 14pt \"Ubuntu\";"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 190, 131, 17));
        login = new QPushButton(centralwidget);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(250, 220, 99, 27));
        Register = new QPushButton(centralwidget);
        Register->setObjectName(QStringLiteral("Register"));
        Register->setGeometry(QRect(450, 220, 99, 27));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(393, 226, 67, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(330, 330, 181, 141));
        drop_box->setCentralWidget(centralwidget);
        menubar = new QMenuBar(drop_box);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        drop_box->setMenuBar(menubar);
        statusbar = new QStatusBar(drop_box);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        drop_box->setStatusBar(statusbar);

        retranslateUi(drop_box);

        QMetaObject::connectSlotsByName(drop_box);
    } // setupUi

    void retranslateUi(QMainWindow *drop_box)
    {
        drop_box->setWindowTitle(QApplication::translate("drop_box", "MainWindow", 0));
        label->setText(QApplication::translate("drop_box", "Welcome to MyDropBox", 0));
        label_2->setText(QString());
        login->setText(QApplication::translate("drop_box", "Login", 0));
        Register->setText(QApplication::translate("drop_box", "Register", 0));
        label_3->setText(QApplication::translate("drop_box", "OR", 0));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class drop_box: public Ui_drop_box {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DROP_BOX_H
