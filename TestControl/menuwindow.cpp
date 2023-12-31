//menuwindow.cpp
#include "menuwindow.h"
#include "ui_menuwindow.h"

#include "dialogforcreatingform.h"


//This code initializes the MenuWindow constructor and establishes
//connections between different signals and slots to handle events in the user interface.
MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);  // Setting up the user interface

    // Creating objects
    testWidget = new TestWidget;
    testForm = new CreatingTestForm;
    scroll = new HorizontalScrollArea(3, 3);

    // Adding the scroll to the tests_page in the user interface layout
    ui->tests_page->layout()->addWidget(scroll);

    // Connecting signals to slots
    connect(ui->testsPushButton, &QPushButton::clicked, this, &MenuWindow::creating_Tests_page);

    // Connecting signals from objects to slots in this MenuWindow
    connect(testWidget, &TestWidget::open_menuwindow, this, &MenuWindow::show);
    connect(testForm, &CreatingTestForm::open_menuwindow, this, &MenuWindow::show);
    connect(testForm, &CreatingTestForm::open_menuwindow, this, &MenuWindow::creating_Tests_page);
    connect(this, &MenuWindow::open_menuwindow, this, &MenuWindow::creating_Tests_page);
}


MenuWindow::~MenuWindow()
{
    delete ui;
}


//The slot generated by the Qt environment for the "Tests" button sets the next widget in the
//StackedWidgets and calls the function that generates the current test directory page.
void MenuWindow::on_testsPushButton_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->tests_page);
    creating_Tests_page();

}

//When a specific test is clicked, the current window closes and the selected test opens
void MenuWindow::dynamicPushButton_clicked()
{
    this->close();
    testWidget->show();
}


//This function generates the current test directory,dynamically creating buttons
//by taking names from the test directory. For these buttons, a class QRightClickButton
//was created, which contains the following signals: shift + right click; doubleRightClicked, leftClicked.
void MenuWindow::creating_Tests_page()
{

    for(QRightClickButton* i : dynamic_buttons)
    {
        delete i;
    }
    dynamic_buttons.clear();
    const QSize btnSize = QSize(400, 100);
    QStringList list_dir = count_files_in_dir("..\\TestControl\\alltests");
    int counter = 0;
    bool flag = true; //It is used to determine in which row/column to add to our scroll (from the HorizontalScrollArea class)

    for(QString i : list_dir)
    {
         QRightClickButton* newButton = new QRightClickButton(ui->tests_page);
         newButton->setText(i);
         newButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
         dynamic_buttons.append(newButton);

         // Establishes connections for different button click events
         // Left-click on newButton connected to 'setPath' method in 'testWidget'
         // Left-click on newButton connected to 'dynamicPushButton_clicked' method in 'MenuWindow'
         // Shift + Right-click on newButton connected to 'shift_right_dynamicPushButton_clicked' method in 'MenuWindow'
         // Double right-click on newButton connected to 'double_right_dynamicPushButton_clicked' method in 'MenuWindow'
         connect(newButton, &QRightClickButton::leftClicked,this->testWidget, &TestWidget::setPath);
         connect(newButton, &QRightClickButton::leftClicked, this, &MenuWindow::dynamicPushButton_clicked);
         connect(newButton, &QRightClickButton::shiftRightClicked, this, &MenuWindow::shift_right_dynamicPushButton_clicked);
         connect(newButton, &QRightClickButton::doubleRightClicked, this, &MenuWindow::double_right_dynamicPushButton_clicked);

         if(flag)
         {
            scroll->addWidget(newButton,0, counter);
            flag = false;
            continue;
         }
         if(!flag)
         {
            scroll->addWidget(newButton,1, counter);
            flag = true;
         }
         counter++;
    }

}


//This code handles the event when the "Create" button is clicked.
//It opens a dialog box for user input. If the user clicks "Accept" in the dialog,
//the program creates a new directory for a test using the entered name. If a directory with the same name
//already exists, it displays a warning.
//In either case, it either creates a new test or rejects the user input.
void MenuWindow::on_createPushButton_clicked()
{

    DialogForCreatingForm dlg( this );
    switch( dlg.exec() ) {
    case QDialog::Accepted:{
         connect(this, &MenuWindow::open_creating_tests_form, this->testForm, &CreatingTestForm::generate_creating_form);
         QDir dir(QString("..\\TestControl\\alltests\\%1\\").arg(dlg.getInput()));
         QFile file(QString("..\\TestControl\\alltests\\%1\\%1.txt").arg(dlg.getInput().arg(dlg.getInput())));
         if(!dir.exists())
         {
            qDebug() << dlg.getInput();
            qDebug() << "Accepted";

            dir.setPath("..\\TestControl\\alltests\\");
            testForm->set_path_to_test(QString("..\\TestControl\\alltests\\%1\\").arg(dlg.getInput()));
            testForm->set_name_of_test(QString("%1.txt").arg(dlg.getInput()));
            dir.mkdir(dlg.getInput());
            emit open_creating_tests_form();
            file.open(QIODevice::ReadWrite);
            file.close();

            this->close();
            testForm->show();
         }
         else
         {
            QMessageBox::warning(this, "TestControl","The same name of the test already exist!");
         }
         break;
    }
    case QDialog::Rejected:{

         qDebug() << "Rejected";
         break;
    }
    default:{
         qDebug() << "Unexpected";
    }

    }

}


//Deletes the current test by removing it from the directory and
//emits the signal creating_Tests_page, which triggers the reloading of the tests directory.
void MenuWindow::shift_right_dynamicPushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "TestControl", "Are you sure?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
         QRightClickButton* sender_button = qobject_cast<QRightClickButton*>(sender());
         QString path = QString("..\\TestControl\\alltests\\%1\\").arg(sender_button->text());
         QDir dir(path);
         dir.removeRecursively();
         emit creating_Tests_page();



    }
}


// Responds to a double right-click event on a QRightClickButton
// Retrieves the sender button and constructs the path and name for the selected test
// Sets the path and name of the test in the 'testForm' object
// Switches 'testForm' to the creating form for editing a slide
// Closes the current window and shows the 'testForm'
void MenuWindow::double_right_dynamicPushButton_clicked()
{
    QRightClickButton* sender_button = qobject_cast<QRightClickButton*>(sender());
    QString path_to_test = QString("..\\TestControl\\alltests\\%1\\").arg(sender_button->text());
    QString name_of_test = QString("%1.txt").arg(sender_button->text());
    testForm->set_path_to_test(path_to_test);
    testForm->set_name_of_test(name_of_test);
    testForm->setCreatingFormForEditSlide();

    this->close();
    testForm->show();

}


void MenuWindow::on_exitPushButton_clicked()
{
    QApplication::exit();
}

