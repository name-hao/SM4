#include "stdafx.h"
#include <QSqlError>
#include <QString>
#include "Login.h"
#include "MyButton.h"
#include "En_Decrypt.h"
#include <QDebug>

Login::Login( Data_Manager& database, QWidget *parent )
    : QDialog( parent ), my_Database{ database }
{
    ui.setupUi(this);

    //setWindowFlags( Qt::FramelessWindowHint );
    connect( ui.exit_Button, SIGNAL( clicked( ) ), this, SLOT( exitProgram( ) ) );
    connect( ui.login_Button, SIGNAL( clicked( ) ), this, SLOT( login_Method( ) ) );
    connect( ui.register_Button, SIGNAL( clicked( ) ), this, SLOT( register_Method( ) ));
    //�����ж����ݿ��Ƿ����ӳɹ�
    //QMessageBox::about( this, u8"���ݿ���Ϣ", QString::number(my_Database.isOpen( )) );
}

Login::~Login()
{
}

void Login::closeEvent( QCloseEvent * e )
{  
    QApplication::exit( 0 );
}

void Login::login_Method( )
{
    QString user_name = ui.user_name_LineEdit->text( );  
    QString user_password =ui.password_LineEdit->text();
    if ( user_name == "" )
    {
        QMessageBox::about( this, u8"��¼��Ϣ", u8"�������û���" );
        ui.user_name_LineEdit->setFocus( );
        return;
    }
    if ( user_password == "" )
    {
        QMessageBox::about( this, u8"��¼��Ϣ", u8"����������" );
        ui.password_LineEdit->setFocus( );
        return;
    }
    if ( my_Database.is_login_Success( user_name, user_password ) )
    {
        qDebug( ) << u8"�û���������ȷ" << endl;
        accept( );
        //this->close( );
    }
    else
    {
        QMessageBox::about( this, u8"��¼��Ϣ", u8"�û����������������������" );
        ui.password_LineEdit->clear( );
        ui.password_LineEdit->setFocus( );
        return;
    }
}

void Login::register_Method( )
{
    QString user_name = ui.user_name_LineEdit->text( );
    QString user_password = ui.password_LineEdit->text( );
    if ( user_name == "" )
    {
        QMessageBox::about( this, u8"ע����Ϣ", u8"�������û���" );
        ui.user_name_LineEdit->setFocus( );
        return;
    }
    if ( user_password == "" )
    {
        QMessageBox::about( this, u8"ע����Ϣ", u8"����������" );
        ui.password_LineEdit->setFocus( );
        return;
    }
    if ( my_Database.is_User_Exit( user_name ) )
    {
        QMessageBox::about( this, u8"ע����Ϣ", u8"�û����Ѿ����ڣ�����������" );
        ui.user_name_LineEdit->clear( );
        ui.user_name_LineEdit->setFocus( );
        return;
    }
    if ( my_Database.add_User( user_name, user_password ) )
    {
        QMessageBox::about( this, u8"ע����Ϣ", u8"ע��ɹ������¼" );
        return;
    }
    else
    {
        QMessageBox::about( this, u8"ע����Ϣ", u8"ע��ʧ�ܣ�������" );
        return;
    }
}

void Login::exitProgram( )
{
    this->close( );
}
