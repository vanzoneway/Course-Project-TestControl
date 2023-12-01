//qrightclickbutton.cpp
#include "qrightclickbutton.h"

QRightClickButton::QRightClickButton(QWidget *parent) :
    QPushButton(parent)
{
}


void QRightClickButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton && QApplication::keyboardModifiers() == Qt::ShiftModifier)
        emit shiftRightClicked();
    if(e->button()==Qt::LeftButton)
        emit leftClicked();
}


void QRightClickButton::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->button() == Qt::RightButton && e->button() == Qt::RightButton)
    {
        emit doubleRightClicked();
    }else{
        QWidget::mouseDoubleClickEvent(e);
    }
}
