//dialogforcreatingform.h
#ifndef DIALOGFORCREATINGFORM_H
#define DIALOGFORCREATINGFORM_H
#include <QDialog>
#include <QDir>
#include <QString>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
class DialogForCreatingForm : public QDialog {
    Q_OBJECT

public:
    DialogForCreatingForm( QWidget* parent = 0 );
    ~DialogForCreatingForm();

    QString getInput() const;

signals:

    void open_creating_tests_page();


private:
    QLineEdit* m_edit;
};

#endif // DIALOGFORCREATINGFORM_H
