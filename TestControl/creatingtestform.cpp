//creatingtestform.cpp
#include "creatingtestform.h"
#include "ui_creatingtestform.h"

CreatingTestForm::CreatingTestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreatingTestForm)
{
    ui->setupUi(this);

    generate_image();
    connect(ui->cancelPushButton, SIGNAL(clicked(bool)), this, SLOT(cancelPushButton_clicked()));


}


void CreatingTestForm::set_path_to_test(const QString& path)
{
    path_to_test = path;
}


void CreatingTestForm::set_name_of_test(const QString &name)
{
    name_of_test = name;
}


CreatingTestForm::~CreatingTestForm()
{
    delete ui;
}


void CreatingTestForm::generate_creating_form()
{
    ui->numOfSlideLabel->setText(QString("Slide №") + QString("%1").arg(num_of_slide + 1));
    create_current_info_map(myTest, num_of_slide);
    ui->justQuestionLineEdit->setText(myTest[num_of_slide]["question"]);
    imgLabel->setCurrentIMG(path_to_IMG);

}


void CreatingTestForm::setCreatingFormForEditSlide()
{
    myTest = parse_txt_to_test(path_to_test + name_of_test);
    is_chosen = true;
    is_next = true;
    num_of_slide = 0;
    ui->numOfSlideLabel->setText(QString("Slide №") + QString("%1").arg(num_of_slide + 1));
    path_to_IMG = myTest[num_of_slide]["img"];
    imgLabel->setCurrentIMG(path_to_IMG);
    ui->justQuestionLineEdit->setText(myTest[num_of_slide]["question"]);
    is_editor = true;


}


void CreatingTestForm::cancelPushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "TestControl", "Are you sure?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        if(!is_editor)
        {
            QDir dir(path_to_test);
            dir.removeRecursively();
        }

        num_of_slide = 0;
        num_of_right_answer = "NONE";
        is_chosen = false;
        is_next = false;
        is_editor = false;
        path_to_test = "";
        name_of_test = "";
        //    "IMG_URL|Question|num_of_questions|number_of_right_question|question1/question2/../questionN|"
        info_in_text_file = "%1|%2|%3|%4|%5";
        myTest.clear();
        buttons_list.clear();



        this->close();
        emit open_menuwindow();

    }

}


void CreatingTestForm::on_savePushButton_clicked()
{

    if(is_avaiable_to_write_in_txt_file(myTest))
    {
        put_map_into_file(myTest, path_to_test + name_of_test);
        num_of_slide = 0;
        num_of_right_answer = "NONE";
        is_chosen = false;
        is_next = false;
        is_editor = false;
        path_to_test = "";
        name_of_test = "";
        //    "IMG_URL|Question|num_of_questions|number_of_right_question|question1/question2/../questionN|"
        info_in_text_file = "%1|%2|%3|%4|%5";
        myTest.clear();
        buttons_list.clear();
        this->close();
        emit open_menuwindow();
    }
    else
    {
          QMessageBox::warning(this, "TestControl","Add questions everywhere!");
    }

}


void CreatingTestForm::on_editQuestionsPushButton_clicked()
{
    num_of_right_answer = myTest[num_of_slide]["number_of_right_answer"];
    ui->stackedWidget->setCurrentWidget(ui->addAnswersWidget);
    QStringList list = parse_line_into_questions(myTest[num_of_slide]["variants_of_answers"]);
    for(QString button_text : list)
    {
        if(button_text != "" && button_text != "NONE"){
            QRightClickButton* new_button = new QRightClickButton(ui->addAnswersWidget);
            new_button->setText(button_text);
            new_button->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
            connect(new_button, &QRightClickButton::shiftRightClicked, this, &CreatingTestForm::onRemovedButton);
            connect(new_button, &QRightClickButton::leftClicked, this, &CreatingTestForm::chooseRightAnswer);
            buttons_list.append(new_button);
            ui->verticalLayout_forQuestions->insertWidget(ui->verticalLayout_forQuestions->count(),new_button);
        }

    }
    if(!buttons_list.isEmpty() && num_of_right_answer != "NONE")
    {
        QRightClickButton* button = buttons_list[num_of_right_answer.toInt() - 1];
        button->setStyleSheet("background-color: green");
    }

}


void CreatingTestForm::on_cancelPushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->creatingMenuWidget);
    for(QRightClickButton* i : buttons_list)
    {
        delete i;
    }
    buttons_list.clear();
    is_chosen = false;
}


void CreatingTestForm::create_current_info_map(QMap<int, QMap<QString, QString>>& tmp_map,int num_of_slide)
{
    if(tmp_map[num_of_slide].isEmpty())
    {
        QMap<QString, QString> tmp_slide_map;
        tmp_slide_map["img"] = "NONE";
        tmp_slide_map["question"] = "NONE";
        tmp_slide_map["amount_of_questions"] = "NONE";
        tmp_slide_map["number_of_right_answer"] = "NONE";
        tmp_slide_map["variants_of_answers"] = "NONE";

        tmp_map[num_of_slide] = tmp_slide_map;
        is_next = false;
    }
    num_of_right_answer = myTest[num_of_slide]["number_of_right_answer"];
    is_next = is_avaiable_nextSlidePushButton();
    is_chosen = is_next;
    path_to_IMG = myTest[num_of_slide]["img"];
}


bool CreatingTestForm::is_avaiable_nextSlidePushButton()
{
    QString question, amount_of_questions, number_of_right_answer, variants_of_answer;
    question = myTest[num_of_slide]["question"];
    amount_of_questions = myTest[num_of_slide]["amount_of_questions"];
    number_of_right_answer = myTest[num_of_slide]["number_of_right_answer"];
    variants_of_answer = myTest[num_of_slide]["variants_of_answer"];
    if(question != "NONE" && amount_of_questions != "NONE" && number_of_right_answer != "NONE" && variants_of_answer != "NONE")
    {
        return true;
    }
    else
    {
        return false;
    }

}


void CreatingTestForm::on_addQuestionPushButton_clicked()
{
    QString button_text = ui->questionLineEdit->text();
    QRightClickButton* new_button = new QRightClickButton(ui->addAnswersWidget);
    new_button->setText(button_text);
    new_button->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    connect(new_button, &QRightClickButton::shiftRightClicked, this, &CreatingTestForm::onRemovedButton);
    connect(new_button, &QRightClickButton::leftClicked, this, &CreatingTestForm::chooseRightAnswer);
    buttons_list.append(new_button);
    ui->verticalLayout_forQuestions->insertWidget(ui->verticalLayout_forQuestions->count(),new_button);
    ui->questionLineEdit->setText("");

}


void CreatingTestForm::onRemovedButton()
{
    QRightClickButton* button = qobject_cast<QRightClickButton*>(sender());
    buttons_list.removeOne(button);
    delete button;
}


QString CreatingTestForm::get_number_of_right_answer(const QList<QRightClickButton*>& list)
{
    int counter = 1;
    for(QRightClickButton* btn : list)
    {
        if(btn->styleSheet() == "background-color: green")
        {
            return QString("%1").arg(counter);
        }
        counter++;
    }
    if(counter >= list.size())
        return QString("NONE");
}


void CreatingTestForm::on_savePushButton_2_clicked()
{
    if(ui->justQuestionLineEdit->text() == "")
    {
        myTest[num_of_slide]["question"] = "NONE";
    }
    else
    {
        myTest[num_of_slide]["question"] = ui->justQuestionLineEdit->text();
    }
    myTest[num_of_slide]["amount_of_questions"] = QString("%1").arg(buttons_list.size());
    myTest[num_of_slide]["number_of_right_answer"] = get_number_of_right_answer(buttons_list);
    QString variants_of_answers;
    for(QRightClickButton* i : buttons_list)
    {
        variants_of_answers += i->text() + '/';
        delete i;
    }
    variants_of_answers.removeAt(variants_of_answers.size()-1);
    buttons_list.clear();
    myTest[num_of_slide]["variants_of_answers"] = variants_of_answers;
    ui->stackedWidget->setCurrentWidget(ui->creatingMenuWidget);
    is_next = is_avaiable_nextSlidePushButton();

}


void CreatingTestForm::chooseRightAnswer()
{
    QRightClickButton* button = qobject_cast<QRightClickButton*>(sender());

    int counter = 1;
    if(!is_chosen)
    {
        for(QRightClickButton* b : buttons_list)
        {
            if(b == button){
                num_of_right_answer = QString("%1").arg(counter);
                break;
            }
            counter++;

        }
        button->setStyleSheet("background-color: green");
        is_chosen = true;
        return;
    }
    else if(num_of_right_answer != "NONE")
    {
        if(buttons_list[num_of_right_answer.toInt() - 1] == button && is_chosen)
        {
            button->setStyleSheet("");
            is_chosen = false;
            num_of_right_answer = "NONE";
        }

        return;
    }




}


void CreatingTestForm::on_nextSlideButton_clicked()
{

    if(is_next)
    {
        num_of_slide++;
        generate_creating_form();


    }
    else
    {
        QMessageBox::warning(this, "TestControl","This slide isn't created yet");
    }
}


void CreatingTestForm::on_prevPushButton_clicked()
{
    if(num_of_slide > 0)
    {
        num_of_slide--;
        generate_creating_form();

    }
}


void CreatingTestForm::on_addImagePushButton_clicked()
{
    imgLabel->is_changed = false;
    ui->stackedWidget->setCurrentWidget(ui->addImageWidget);
}


void CreatingTestForm::generate_image()
{
    QVBoxLayout* layout = new QVBoxLayout(ui->addImageWidget);
    imgLabel = new AspectRatioPixmapLabel;
    imgLabel->setText("NONE");
    imgLabel->setAlignment(Qt::AlignCenter);
    imgLabel->setClicable(true);
    QPushButton* returnPushButton = new QPushButton;
    returnPushButton->setText("OK");
    connect(returnPushButton, &QPushButton::clicked, this, &CreatingTestForm::returnPushButton_clicked);
    layout->addWidget(imgLabel);
    layout->addWidget(returnPushButton);

}


void CreatingTestForm::returnPushButton_clicked()
{
    if(imgLabel->is_changed){
        path_to_IMG = imgLabel->getPath_to_IMG();
        QFileInfo fileInfo(path_to_IMG);
        QString newFilePath = path_to_test + fileInfo.fileName();
        if(is_need_to_delete_IMG(myTest[num_of_slide]["img"]))
        {
            QFile file(myTest[num_of_slide]["img"]);
            file.remove();
            file.close();
        }


        if (QFile::copy(path_to_IMG, newFilePath)) {
            qDebug() << "Файл скопирован успешно: " << newFilePath;

        } else {

            qDebug() << "Не удалось скопировать файл";
        }
        path_to_IMG == "NONE" ? path_to_IMG : path_to_IMG = newFilePath;
        myTest[num_of_slide]["img"] = path_to_IMG;
        imgLabel->is_changed = false;
    }
    ui->stackedWidget->setCurrentWidget(ui->creatingMenuWidget);


}


bool CreatingTestForm::is_need_to_delete_IMG(const QString& path_to_img)
{
    int counter = 0;
    for(QMap<QString, QString> i : myTest)
    {
        if (i["img"] == path_to_img)
            counter++;
    }
    return counter >= 2 ? false : true;
}


void CreatingTestForm::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Delete)
    {

        QMessageBox::StandardButton reply = QMessageBox::question(this, "TestControl", "Are you sure?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            removeCurrentPage(num_of_slide);
            generate_creating_form();
        }
    }
}


void CreatingTestForm::removeCurrentPage(int index_to_remove)
{
    if(index_to_remove >= 0 && index_to_remove < myTest.size())
    {
        for(int i = index_to_remove; i < myTest.size() - 1; ++i)
        {
            myTest[i] = myTest[i+1];
        }
        if(index_to_remove == myTest.size() - 1 && index_to_remove > 0)
            num_of_slide--;
        myTest.remove(myTest.size() - 1);
    }

}

