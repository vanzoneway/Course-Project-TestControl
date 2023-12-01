/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *tests_page;
    QVBoxLayout *verticalLayout;
    QPushButton *createPushButton;
    QWidget *menu_page;
    QVBoxLayout *verticalLayout_3;
    QPushButton *testsPushButton;
    QPushButton *exitPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName("MenuWindow");
        MenuWindow->resize(857, 473);
        centralwidget = new QWidget(MenuWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        tests_page = new QWidget();
        tests_page->setObjectName("tests_page");
        verticalLayout = new QVBoxLayout(tests_page);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(9, -1, -1, -1);
        createPushButton = new QPushButton(tests_page);
        createPushButton->setObjectName("createPushButton");

        verticalLayout->addWidget(createPushButton);

        stackedWidget->addWidget(tests_page);
        menu_page = new QWidget();
        menu_page->setObjectName("menu_page");
        verticalLayout_3 = new QVBoxLayout(menu_page);
        verticalLayout_3->setObjectName("verticalLayout_3");
        testsPushButton = new QPushButton(menu_page);
        testsPushButton->setObjectName("testsPushButton");
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(testsPushButton->sizePolicy().hasHeightForWidth());
        testsPushButton->setSizePolicy(sizePolicy);
        testsPushButton->setMinimumSize(QSize(200, 0));

        verticalLayout_3->addWidget(testsPushButton);

        exitPushButton = new QPushButton(menu_page);
        exitPushButton->setObjectName("exitPushButton");
        sizePolicy.setHeightForWidth(exitPushButton->sizePolicy().hasHeightForWidth());
        exitPushButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(exitPushButton);

        stackedWidget->addWidget(menu_page);

        verticalLayout_2->addWidget(stackedWidget);

        MenuWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MenuWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 857, 21));
        MenuWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MenuWindow);
        statusbar->setObjectName("statusbar");
        MenuWindow->setStatusBar(statusbar);

        retranslateUi(MenuWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MenuWindow)
    {
        MenuWindow->setWindowTitle(QCoreApplication::translate("MenuWindow", "TestControl", nullptr));
        createPushButton->setText(QCoreApplication::translate("MenuWindow", "Create Test", nullptr));
        testsPushButton->setText(QCoreApplication::translate("MenuWindow", "Tests", nullptr));
        exitPushButton->setText(QCoreApplication::translate("MenuWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
