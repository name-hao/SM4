#include "stdafx.h"
#include "MyButton.h"

MyButton::MyButton(QWidget *parent)
    : QPushButton(parent)
{
}

MyButton::~MyButton()
{
}

void MyButton::mouseReleaseEvent( QMouseEvent * ev )
{
    if ( Qt::LeftButton == ev->button( ) )
    {

        emit clicked( );

    }
    else if ( Qt::RightButton == ev->button( ) )
    {
        if ( this->text() == u8"��¼")
        {
            this->setText( u8"ע��" );
        }
        else
        {
            this->setText( u8"��¼" );
        }
    }
}
