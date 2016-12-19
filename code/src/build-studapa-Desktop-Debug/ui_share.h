/********************************************************************************
** Form generated from reading UI file 'share.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHARE_H
#define UI_SHARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_share
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *share)
    {
        if (share->objectName().isEmpty())
            share->setObjectName(QStringLiteral("share"));
        share->resize(800, 600);
        centralwidget = new QWidget(share);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 170, 251, 17));
        share->setCentralWidget(centralwidget);
        menubar = new QMenuBar(share);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        share->setMenuBar(menubar);
        statusbar = new QStatusBar(share);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        share->setStatusBar(statusbar);

        retranslateUi(share);

        QMetaObject::connectSlotsByName(share);
    } // setupUi

    void retranslateUi(QMainWindow *share)
    {
        share->setWindowTitle(QApplication::translate("share", "MainWindow", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class share: public Ui_share {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHARE_H
