/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.2.1
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtCore/qglobal.h>

static const unsigned char qt_resource_data[] = {
  // /home/bee/Desktop/shubham/studapa/register.cpp
  0x0,0x0,0x0,0xc9,
  0x23,
  0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,0x20,0x22,0x72,0x65,0x67,0x69,0x73,0x74,0x65,
  0x72,0x2e,0x68,0x22,0xa,0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,0x20,0x22,0x75,
  0x69,0x5f,0x72,0x65,0x67,0x69,0x73,0x74,0x65,0x72,0x2e,0x68,0x22,0xa,0xa,0x72,
  0x65,0x67,0x69,0x73,0x74,0x65,0x72,0x3a,0x3a,0x72,0x65,0x67,0x69,0x73,0x74,0x65,
  0x72,0x28,0x51,0x57,0x69,0x64,0x67,0x65,0x74,0x20,0x2a,0x70,0x61,0x72,0x65,0x6e,
  0x74,0x29,0x20,0x3a,0xa,0x20,0x20,0x20,0x20,0x51,0x4d,0x61,0x69,0x6e,0x57,0x69,
  0x6e,0x64,0x6f,0x77,0x28,0x70,0x61,0x72,0x65,0x6e,0x74,0x29,0x2c,0xa,0x20,0x20,
  0x20,0x20,0x75,0x69,0x28,0x6e,0x65,0x77,0x20,0x55,0x69,0x3a,0x3a,0x72,0x65,0x67,
  0x69,0x73,0x74,0x65,0x72,0x29,0xa,0x7b,0xa,0x20,0x20,0x20,0x20,0x75,0x69,0x2d,
  0x3e,0x73,0x65,0x74,0x75,0x70,0x55,0x69,0x28,0x74,0x68,0x69,0x73,0x29,0x3b,0xa,
  0x7d,0xa,0xa,0x72,0x65,0x67,0x69,0x73,0x74,0x65,0x72,0x3a,0x3a,0x7e,0x72,0x65,
  0x67,0x69,0x73,0x74,0x65,0x72,0x28,0x29,0xa,0x7b,0xa,0x64,0x65,0x6c,0x65,0x74,
  0x65,0x20,0x75,0x69,0x3b,0xa,0x7d,0xa,
  
};

static const unsigned char qt_resource_name[] = {
  // register.cpp
  0x0,0xc,
  0x5,0xd2,0x8b,0x30,
  0x0,0x72,
  0x0,0x65,0x0,0x67,0x0,0x69,0x0,0x73,0x0,0x74,0x0,0x65,0x0,0x72,0x0,0x2e,0x0,0x63,0x0,0x70,0x0,0x70,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
  // :/register.cpp
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,

};

QT_BEGIN_NAMESPACE

extern Q_CORE_EXPORT bool qRegisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

extern Q_CORE_EXPORT bool qUnregisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

QT_END_NAMESPACE


int QT_MANGLE_NAMESPACE(qInitResources_abcd)()
{
    QT_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_abcd))

int QT_MANGLE_NAMESPACE(qCleanupResources_abcd)()
{
    QT_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_DESTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qCleanupResources_abcd))

