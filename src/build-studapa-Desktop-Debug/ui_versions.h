/********************************************************************************
** Form generated from reading UI file 'versions.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERSIONS_H
#define UI_VERSIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_versions
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *pushButton_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *versions)
    {
        if (versions->objectName().isEmpty())
            versions->setObjectName(QStringLiteral("versions"));
        versions->resize(843, 654);
        centralwidget = new QWidget(versions);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(220, 150, 471, 401));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(580, 570, 110, 27));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(280, 570, 299, 31));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        horizontalLayout_2->addLayout(horizontalLayout);

        versions->setCentralWidget(centralwidget);
        menubar = new QMenuBar(versions);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 843, 25));
        versions->setMenuBar(menubar);
        statusbar = new QStatusBar(versions);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        versions->setStatusBar(statusbar);

        retranslateUi(versions);

        QMetaObject::connectSlotsByName(versions);
    } // setupUi

    void retranslateUi(QMainWindow *versions)
    {
        versions->setWindowTitle(QApplication::translate("versions", "MainWindow", 0));
        pushButton_2->setText(QApplication::translate("versions", "Back", 0));
        pushButton->setText(QApplication::translate("versions", "Download", 0));
    } // retranslateUi

};

namespace Ui {
    class versions: public Ui_versions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSIONS_H
