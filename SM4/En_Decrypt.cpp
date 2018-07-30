#include "stdafx.h"
#include "En_Decrypt.h"
#include "SM4_Algorithm.h"
#include <QString>
#include "string.h"
#include <QDebug>
void Encrypt_String( QByteArray& source_array, QByteArray& result_array, unsigned char key[16] )
{
    result_array.resize( source_array.length( ) );
    sm4_context ctx;
    sm4_setkey_enc( &ctx, key );
    sm4_crypt_ecb( &ctx, 1, source_array.length( ), (unsigned char*)source_array.data( ), (unsigned char*)result_array.data( ) );
}

void Decrypt_String( QByteArray&  source_array, QByteArray& result_array, unsigned char key[16] )
{
    
    result_array.resize( source_array.length( ) );
    result_array.fill( '\0' );
    /*qDebug( ) << u8"----------������ܺ���----------" << endl;
    qDebug( ) << u8"ԭʼlength: " << source_array.length( ) << endl;
    qDebug( ) << u8"ԭʼchar: " << source_array.data( ) << endl;
    qDebug( ) << u8"���char: " << result_array.data( ) << endl;*/
    sm4_context ctx;
    sm4_setkey_dec( &ctx, key );
    sm4_crypt_ecb( &ctx, 0, source_array.length( ), (unsigned char*)source_array.data( ), (unsigned char*)result_array.data( ) );
    /*qDebug( ) << u8"----------���ܳɹ�----------" << endl;
    qDebug( ) << u8"���char: " << result_array.data( ) << endl;
    qDebug( ) << u8"----------���ܺ������н���----------" << endl;*/
}

void Encrypt_ByteArray( QByteArray & source_file, QByteArray& result_file, unsigned char key[16] )
{
    result_file.resize( source_file.size( ) );
    sm4_context ctx;
    sm4_setkey_enc( &ctx, key );
    sm4_crypt_ecb( &ctx, 1, source_file.length( ), (unsigned char*)source_file.data( ), (unsigned char*)result_file.data( ) );
}

void Decrypt_ByteArray( QByteArray & source_file, QByteArray& result_file, unsigned char key[16] )
{
    result_file.resize( source_file.size( ) );
    sm4_context ctx;
    sm4_setkey_dec( &ctx, key );
    sm4_crypt_ecb( &ctx, 0, source_file.length( ), (unsigned char*)source_file.data( ), (unsigned char*)result_file.data( ) );
}