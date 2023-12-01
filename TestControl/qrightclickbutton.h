//qrightclickbutton.h
#ifndef QRIGHTCLICKBUTTON_H
#define QRIGHTCLICKBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QApplication>

class QRightClickButton : public QPushButton
{
    Q_OBJECT

public:
    explicit QRightClickButton(QWidget *parent = 0);

private slots:
    void mousePressEvent(QMouseEvent *e);

    void mouseDoubleClickEvent(QMouseEvent* e);

signals:
    void shiftRightClicked();

    void leftClicked();

    void doubleRightClicked();

};

#endif // QRIGHTCLICKBUTTON_H
