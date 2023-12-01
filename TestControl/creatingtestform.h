//creatingtestform.h
#ifndef CREATINGTESTFORM_H
#define CREATINGTESTFORM_H

#include <QWidget>
#include <QString>
#include <QDir>
#include <QFile>
#include <QMap>
#include <QLineEdit>
#include <QList>
#include <QMessageBox>
#include <QPixmap>
#include <QHBoxLayout>
#include <QFileInfo>
#include <QKeyEvent>
#include "aspectratiopixmaplabel.h"
#include "dialogforcreatingform.h"
#include "readqfile.h"
#include "qrightclickbutton.h"


namespace Ui {
class CreatingTestForm;
}

class CreatingTestForm : public QWidget
{
    Q_OBJECT

public:

    explicit CreatingTestForm(QWidget *parent = nullptr);

    void set_path_to_test(const QString& path);

    void set_name_of_test(const QString& name);

    ~CreatingTestForm();


public slots:

    void generate_creating_form();

    void setCreatingFormForEditSlide();

private slots:

    void cancelPushButton_clicked();

    void on_editQuestionsPushButton_clicked();

    void on_cancelPushButton_2_clicked();

    void on_addQuestionPushButton_clicked();

    void onRemovedButton();

    void on_savePushButton_2_clicked();

    void chooseRightAnswer();

    void on_nextSlideButton_clicked();

    void on_prevPushButton_clicked();

    void on_savePushButton_clicked();

    void on_addImagePushButton_clicked();

    void generate_image();

    void returnPushButton_clicked();

    bool is_need_to_delete_IMG(const QString& path_to_img);

    void keyPressEvent(QKeyEvent* e);

    void removeCurrentPage(int index_to_remove);


private:

    void create_current_info_map(QMap<int, QMap<QString, QString>>& tmp_map,int num_of_slide);

    bool is_avaiable_nextSlidePushButton();

    QString get_number_of_right_answer(const QList<QRightClickButton*>& list);


signals:

    void open_menuwindow();

private:

    QString num_of_right_answer = "NONE";
    QString info_in_text_file = "%1|%2|%3|%4|%5";

    Ui::CreatingTestForm *ui;

    QList<QRightClickButton*> buttons_list;
    AspectRatioPixmapLabel* imgLabel;
    QMap<int, QMap<QString, QString>> myTest;

    QString path_to_test;
    QString name_of_test;
    QString path_to_IMG;

    bool is_chosen = false;
    bool is_next = false;
    bool is_editor = false;
    int num_of_slide = 0;


};

#endif // CREATINGTESTFORM_H
