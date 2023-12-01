#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QDebug>
#include <QLabel>
#include <QTime>
//menuwindow.h
#include <QMainWindow>
#include <QDir>
#include <QString>
#include <QGridLayout>
#include <QSplitter>
#include <QPushButton>
#include <QFile>
#include <QMouseEvent>
#include "readqfile.h"
#include "testwidget.h"
#include "horizontalscrollarea.h"
#include "testwidget.h"
#include "creatingtestform.h"
#include "qrightclickbutton.h"


namespace Ui {
class MenuWindow;
}


class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private slots:

    void dynamicPushButton_clicked();

    void on_testsPushButton_clicked();

    void creating_Tests_page();

    void on_createPushButton_clicked();

    void shift_right_dynamicPushButton_clicked();

    void double_right_dynamicPushButton_clicked();

    void on_exitPushButton_clicked();

signals:

    void open_creating_tests_form();

    void open_menuwindow();

private:

    Ui::MenuWindow *ui;

    HorizontalScrollArea* scroll;
    TestWidget* testWidget;
    CreatingTestForm* testForm;

    QVector<QRightClickButton*> dynamic_buttons;
};

#endif // MENUWINDOW_H
