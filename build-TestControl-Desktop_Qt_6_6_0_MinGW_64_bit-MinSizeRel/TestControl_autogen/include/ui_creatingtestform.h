/********************************************************************************
** Form generated from reading UI file 'creatingtestform.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATINGTESTFORM_H
#define UI_CREATINGTESTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreatingTestForm
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *creatingMenuWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *numOfSlideLabel;
    QPushButton *addImagePushButton;
    QPushButton *editQuestionsPushButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevPushButton;
    QPushButton *savePushButton;
    QPushButton *cancelPushButton;
    QPushButton *nextSlideButton;
    QWidget *addAnswersWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *justQuestionLabel;
    QLineEdit *justQuestionLineEdit;
    QLineEdit *questionLineEdit;
    QPushButton *addQuestionPushButton;
    QVBoxLayout *verticalLayout_forQuestions;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *savePushButton_2;
    QPushButton *cancelPushButton_2;
    QWidget *addImageWidget;

    void setupUi(QWidget *CreatingTestForm)
    {
        if (CreatingTestForm->objectName().isEmpty())
            CreatingTestForm->setObjectName("CreatingTestForm");
        CreatingTestForm->resize(879, 383);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreatingTestForm->sizePolicy().hasHeightForWidth());
        CreatingTestForm->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(CreatingTestForm);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(CreatingTestForm);
        widget->setObjectName("widget");
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName("stackedWidget");
        creatingMenuWidget = new QWidget();
        creatingMenuWidget->setObjectName("creatingMenuWidget");
        verticalLayout_3 = new QVBoxLayout(creatingMenuWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        numOfSlideLabel = new QLabel(creatingMenuWidget);
        numOfSlideLabel->setObjectName("numOfSlideLabel");

        verticalLayout_3->addWidget(numOfSlideLabel);

        addImagePushButton = new QPushButton(creatingMenuWidget);
        addImagePushButton->setObjectName("addImagePushButton");
        sizePolicy.setHeightForWidth(addImagePushButton->sizePolicy().hasHeightForWidth());
        addImagePushButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(addImagePushButton);

        editQuestionsPushButton = new QPushButton(creatingMenuWidget);
        editQuestionsPushButton->setObjectName("editQuestionsPushButton");
        sizePolicy.setHeightForWidth(editQuestionsPushButton->sizePolicy().hasHeightForWidth());
        editQuestionsPushButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(editQuestionsPushButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        prevPushButton = new QPushButton(creatingMenuWidget);
        prevPushButton->setObjectName("prevPushButton");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(prevPushButton->sizePolicy().hasHeightForWidth());
        prevPushButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(prevPushButton);

        savePushButton = new QPushButton(creatingMenuWidget);
        savePushButton->setObjectName("savePushButton");
        sizePolicy.setHeightForWidth(savePushButton->sizePolicy().hasHeightForWidth());
        savePushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(savePushButton);

        cancelPushButton = new QPushButton(creatingMenuWidget);
        cancelPushButton->setObjectName("cancelPushButton");
        sizePolicy.setHeightForWidth(cancelPushButton->sizePolicy().hasHeightForWidth());
        cancelPushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(cancelPushButton);

        nextSlideButton = new QPushButton(creatingMenuWidget);
        nextSlideButton->setObjectName("nextSlideButton");
        sizePolicy1.setHeightForWidth(nextSlideButton->sizePolicy().hasHeightForWidth());
        nextSlideButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(nextSlideButton);


        verticalLayout_3->addLayout(horizontalLayout);

        stackedWidget->addWidget(creatingMenuWidget);
        addAnswersWidget = new QWidget();
        addAnswersWidget->setObjectName("addAnswersWidget");
        verticalLayout_4 = new QVBoxLayout(addAnswersWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        justQuestionLabel = new QLabel(addAnswersWidget);
        justQuestionLabel->setObjectName("justQuestionLabel");

        horizontalLayout_3->addWidget(justQuestionLabel);

        justQuestionLineEdit = new QLineEdit(addAnswersWidget);
        justQuestionLineEdit->setObjectName("justQuestionLineEdit");

        horizontalLayout_3->addWidget(justQuestionLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_3);

        questionLineEdit = new QLineEdit(addAnswersWidget);
        questionLineEdit->setObjectName("questionLineEdit");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(questionLineEdit->sizePolicy().hasHeightForWidth());
        questionLineEdit->setSizePolicy(sizePolicy2);
        questionLineEdit->setMinimumSize(QSize(0, 40));

        verticalLayout_4->addWidget(questionLineEdit);

        addQuestionPushButton = new QPushButton(addAnswersWidget);
        addQuestionPushButton->setObjectName("addQuestionPushButton");

        verticalLayout_4->addWidget(addQuestionPushButton);

        verticalLayout_forQuestions = new QVBoxLayout();
        verticalLayout_forQuestions->setObjectName("verticalLayout_forQuestions");

        verticalLayout_4->addLayout(verticalLayout_forQuestions);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        savePushButton_2 = new QPushButton(addAnswersWidget);
        savePushButton_2->setObjectName("savePushButton_2");

        horizontalLayout_2->addWidget(savePushButton_2);

        cancelPushButton_2 = new QPushButton(addAnswersWidget);
        cancelPushButton_2->setObjectName("cancelPushButton_2");

        horizontalLayout_2->addWidget(cancelPushButton_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(addAnswersWidget);
        addImageWidget = new QWidget();
        addImageWidget->setObjectName("addImageWidget");
        stackedWidget->addWidget(addImageWidget);

        verticalLayout_2->addWidget(stackedWidget);


        verticalLayout->addWidget(widget);


        retranslateUi(CreatingTestForm);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CreatingTestForm);
    } // setupUi

    void retranslateUi(QWidget *CreatingTestForm)
    {
        CreatingTestForm->setWindowTitle(QCoreApplication::translate("CreatingTestForm", "TestControl", nullptr));
        numOfSlideLabel->setText(QCoreApplication::translate("CreatingTestForm", "Here will be the number of slided ", nullptr));
        addImagePushButton->setText(QCoreApplication::translate("CreatingTestForm", "Edit Image", nullptr));
        editQuestionsPushButton->setText(QCoreApplication::translate("CreatingTestForm", "Edit Questions", nullptr));
        prevPushButton->setText(QCoreApplication::translate("CreatingTestForm", "PrevSlide", nullptr));
        savePushButton->setText(QCoreApplication::translate("CreatingTestForm", "Save", nullptr));
        cancelPushButton->setText(QCoreApplication::translate("CreatingTestForm", "Cancel", nullptr));
        nextSlideButton->setText(QCoreApplication::translate("CreatingTestForm", "NextSlide", nullptr));
        justQuestionLabel->setText(QCoreApplication::translate("CreatingTestForm", "Question", nullptr));
        addQuestionPushButton->setText(QCoreApplication::translate("CreatingTestForm", "Add question", nullptr));
        savePushButton_2->setText(QCoreApplication::translate("CreatingTestForm", "Save", nullptr));
        cancelPushButton_2->setText(QCoreApplication::translate("CreatingTestForm", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreatingTestForm: public Ui_CreatingTestForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATINGTESTFORM_H
