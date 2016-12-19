/********************************************************************************
** Form generated from reading UI file 'afterlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFTERLOGIN_H
#define UI_AFTERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_afterlogin
{
public:
    QWidget *centralwidget;
    QTreeView *treeView;
    QLabel *label;
    QPushButton *signout;
    QPushButton *upload_all;
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *select;
    QPushButton *upload;
    QPushButton *share;
    QPushButton *prev;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_2;
    QPushButton *share_2;
    QLabel *label_3;
    QPushButton *down;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *afterlogin)
    {
        if (afterlogin->objectName().isEmpty())
            afterlogin->setObjectName(QStringLiteral("afterlogin"));
        afterlogin->resize(950, 773);
        centralwidget = new QWidget(afterlogin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(250, 130, 541, 431));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 80, 491, 20));
        signout = new QPushButton(centralwidget);
        signout->setObjectName(QStringLiteral("signout"));
        signout->setGeometry(QRect(810, 130, 99, 27));
        upload_all = new QPushButton(centralwidget);
        upload_all->setObjectName(QStringLiteral("upload_all"));
        upload_all->setGeometry(QRect(810, 180, 99, 27));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(820, 90, 81, 31));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(260, 580, 414, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        select = new QPushButton(layoutWidget);
        select->setObjectName(QStringLiteral("select"));

        horizontalLayout->addWidget(select);

        upload = new QPushButton(layoutWidget);
        upload->setObjectName(QStringLiteral("upload"));

        horizontalLayout->addWidget(upload);

        share = new QPushButton(layoutWidget);
        share->setObjectName(QStringLiteral("share"));

        horizontalLayout->addWidget(share);

        prev = new QPushButton(layoutWidget);
        prev->setObjectName(QStringLiteral("prev"));

        horizontalLayout->addWidget(prev);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(360, 650, 148, 62));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(layoutWidget1);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(510, 650, 178, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBox_2 = new QComboBox(layoutWidget2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout_2->addWidget(comboBox_2);

        share_2 = new QPushButton(layoutWidget2);
        share_2->setObjectName(QStringLiteral("share_2"));

        horizontalLayout_2->addWidget(share_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(440, 0, 121, 121));
        down = new QPushButton(centralwidget);
        down->setObjectName(QStringLiteral("down"));
        down->setGeometry(QRect(680, 580, 99, 31));
        afterlogin->setCentralWidget(centralwidget);
        treeView->raise();
        label->raise();
        signout->raise();
        upload_all->raise();
        label_2->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        label_3->raise();
        down->raise();
        prev->raise();
        menubar = new QMenuBar(afterlogin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 950, 25));
        afterlogin->setMenuBar(menubar);
        statusbar = new QStatusBar(afterlogin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        afterlogin->setStatusBar(statusbar);

        retranslateUi(afterlogin);

        QMetaObject::connectSlotsByName(afterlogin);
    } // setupUi

    void retranslateUi(QMainWindow *afterlogin)
    {
        afterlogin->setWindowTitle(QApplication::translate("afterlogin", "MainWindow", 0));
        label->setText(QString());
        signout->setText(QApplication::translate("afterlogin", "Sign Out", 0));
        upload_all->setText(QApplication::translate("afterlogin", "Upload All", 0));
        label_2->setText(QString());
        select->setText(QApplication::translate("afterlogin", "Select", 0));
        upload->setText(QApplication::translate("afterlogin", "Upload", 0));
        share->setText(QApplication::translate("afterlogin", "Share", 0));
        prev->setText(QApplication::translate("afterlogin", "Previous Versions", 0));
        share_2->setText(QApplication::translate("afterlogin", "Share", 0));
        label_3->setText(QString());
        down->setText(QApplication::translate("afterlogin", "Download", 0));
    } // retranslateUi

};

namespace Ui {
    class afterlogin: public Ui_afterlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFTERLOGIN_H
