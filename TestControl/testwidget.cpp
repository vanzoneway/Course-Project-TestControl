//testwidget.cpp
#include "testwidget.h"
#include "ui_testwidget.h"
#include <QDebug>


//The code represents the TestWidget widget used to display and interact with tests.
//Here's an explanation of its functionality:

//Constructor and destructor:
//The constructor sets up the widget's interface, while the destructor releases allocated memory.
//Signal and slots: A connection is established between the activate_generating_slide()
//signal and the generate_slide() slot to generate a new slide upon signal invocation.
//Adding answers:
//The add_answers() function creates buttons with answer options based on the test data.
//Handling the correct answer: The change_style_if_right_answer() function modifies the button style based on the chosen answer.
//Slide generation:
//The generate_slide() function refreshes the test slide, including the question, image, and answer options.
//Button control:
//The make_buttons_unclickable() and delete_dynamic_buttons() functions manage button states during testing.
//Handling keypress events:
//The keyPressEvent() method responds to keypresses, allowing users to use the Enter/Return keys to navigate to the next question and Esc to return to the menu.


TestWidget::TestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWidget)
{
    ui->setupUi(this);
    connect(this, SIGNAL(activate_generating_slide()), this, SLOT(generate_slide()));

}


TestWidget::~TestWidget()
{
    delete ui;
}


void TestWidget::add_answers()
{
    QStringList variants_of_answers = parse_line_into_questions(myTest[num_of_slide]["variants_of_answers"]);

    int counter = 0;
    bool flag = true;
    for(QString i : variants_of_answers)
    {
        QPushButton* newButton = new QPushButton(this);
        newButton->setText(i);
        newButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        button_vector.append(newButton);
        connect(newButton, SIGNAL(clicked(bool)), this, SLOT(change_style_if_right_answer()));
        ui->verticalLayout->addWidget(newButton);
        counter++;
    }
}


void TestWidget::action_if_right_answer()
{
    if(num_of_slide == myTest.count()){
        QMessageBox::information(this, "TestControl",QString("Result: %1/%2").arg(score).arg(num_of_slide));
        this->close();
        score = 0;
        num_of_slide = 0;
        delete_dynamic_buttons();
        if(is_image)
        {
            ui->splitter->widget(0)->deleteLater();
            is_image = false;
        }


        emit open_menuwindow();
    }
    generate_slide();
}


void TestWidget::delete_dynamic_buttons()
{
    for(QPushButton* i : button_vector){

        ui->verticalLayout->removeWidget(i);
        delete(i);
    }
    button_vector.clear();

}


void TestWidget::generate_slide()
{
    can_we_continue = false;
    delete_dynamic_buttons();
    add_image_on_slide();
    add_answers();
    QMap<QString, QString> slide = myTest[num_of_slide];
    ui->questionLabel->setText(slide["question"]);

}


void TestWidget::add_image_on_slide()
{
    imgLabel = new AspectRatioPixmapLabel;
    imgLabel->setText("NONE");

    QString path_to_img = QString(myTest[num_of_slide]["img"]);
    QPixmap pic(path_to_img);

    if(is_image)
    {
        ui->splitter->widget(0)->deleteLater();
        is_image = false;

    }
    if(path_to_img != "NONE" && !pic.isNull())
    {
       ui->splitter->insertWidget(0, imgLabel);
       imgLabel->setPixmap(pic);
       is_image = true;

    }

}


void TestWidget::change_style_if_right_answer()
{
    can_we_continue = true;
    int number_of_right_answer = (myTest[num_of_slide]["number_of_right_answer"]).toInt();
    QStringList variants_of_answers = parse_line_into_questions(myTest[num_of_slide]["variants_of_answers"]);
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if(variants_of_answers[number_of_right_answer-1] == senderButton->text())
    {
        senderButton->setStyleSheet("background-color: green");
        score++;
        num_of_slide++;
        make_buttons_unclickable();

    }
    else
    {
        QPushButton* btn = button_vector[number_of_right_answer-1];
        btn->setStyleSheet("background-color: green");
        senderButton->setStyleSheet("background-color: red");
        num_of_slide++;
        make_buttons_unclickable();
    }

}


void TestWidget::make_buttons_unclickable()
{
    for(QPushButton* i : button_vector)
    {
        i->setEnabled(false);
    }
}


void TestWidget::setPath()
{

    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    path_to_test = QString("../TestControl/alltests/%1/%1.txt").arg(senderButton->text());
    myTest = parse_txt_to_test(path_to_test);
    emit activate_generating_slide();


}


void TestWidget::keyPressEvent(QKeyEvent *e){
    if( (e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return ) &&  can_we_continue)
        action_if_right_answer();
    if(e->key() == Qt::Key_Escape)
    {
        this->close();
        score = 0;
        num_of_slide = 0;
        delete_dynamic_buttons();
        if(is_image)
        {
            ui->splitter->widget(0)->deleteLater();
            is_image = false;
        }


        emit open_menuwindow();
    }

}










