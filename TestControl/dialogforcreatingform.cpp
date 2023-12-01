//dialogforcreatingform.cpp
#include "dialogforcreatingform.h"


DialogForCreatingForm::DialogForCreatingForm( QWidget* parent ) : QDialog( parent ) {
    QBoxLayout* layout = new QHBoxLayout;
    m_edit = new QLineEdit;
    layout->addWidget( m_edit );

    QPushButton* okBtn = new QPushButton( "OK" );
    connect( okBtn, SIGNAL( clicked() ), SLOT( accept() ) );
    layout->addWidget( okBtn );

    QPushButton* cancelBtn = new QPushButton( "Cancel" );
    connect( cancelBtn, SIGNAL( clicked() ), SLOT( reject() ) );
    layout->addWidget( cancelBtn );
    setLayout( layout );
}


DialogForCreatingForm::~DialogForCreatingForm() {
}


QString DialogForCreatingForm::getInput() const {
    return m_edit->text();
}
