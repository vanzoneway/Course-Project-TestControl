//testwidget.h
#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QPixmap>
#include <QKeyEvent>
#include <QKeyEvent>
#include "aspectratiopixmaplabel.h"

#include "horizontalscrollarea.h"
#include "readqfile.h"


namespace Ui {
class TestWidget;
}

class TestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TestWidget(QWidget *parent = nullptr);
    ~TestWidget();

    void add_answers();



private slots:
    void action_if_right_answer();

    void delete_dynamic_buttons();

    void generate_slide();

    void add_image_on_slide();

    void change_style_if_right_answer();

    void make_buttons_unclickable();


public:

    void setPath();

signals:
    void activate_generating_slide();

    void open_menuwindow();

    void continue_test();

protected:
    void keyPressEvent(QKeyEvent *e) override;
private:

    Ui::TestWidget *ui;

    QMap<int, QMap<QString, QString>> myTest;
    QVector<QPushButton*> button_vector;
    QString path_to_test;
    HorizontalScrollArea* scroll;
    AspectRatioPixmapLabel* imgLabel;

    bool is_image = false;
    bool can_we_continue = false;
    int num_of_slide = 0;
    int score = 0;

};

#endif // TESTWIDGET_H
