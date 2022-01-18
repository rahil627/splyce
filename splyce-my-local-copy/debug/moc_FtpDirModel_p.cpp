/****************************************************************************
** Meta object code from reading C++ file 'FtpDirModel_p.h'
**
** Created: Tue Oct 20 03:33:37 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FTP/FtpDirModel_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FtpDirModel_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FtpDirListerOperation[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,
      33,   22,   22,   22, 0x05,
      44,   22,   22,   22, 0x05,
      54,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      75,   22,   22,   22, 0x0a,
      85,   22,   22,   22, 0x0a,
      98,   93,   22,   22, 0x09,
     120,  117,   22,   22, 0x09,
     149,  140,   22,   22, 0x09,
     181,  175,   22,   22, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_FtpDirListerOperation[] = {
    "FtpDirListerOperation\0\0started()\0"
    "finished()\0aborted()\0loginParamsRequest()\0"
    "execute()\0abort()\0info\0listInfo(QUrlInfo)\0"
    "id\0commandStarted(int)\0id,error\0"
    "commandFinished(int,bool)\0state\0"
    "stateChanged(int)\0"
};

const QMetaObject FtpDirListerOperation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FtpDirListerOperation,
      qt_meta_data_FtpDirListerOperation, 0 }
};

const QMetaObject *FtpDirListerOperation::metaObject() const
{
    return &staticMetaObject;
}

void *FtpDirListerOperation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FtpDirListerOperation))
        return static_cast<void*>(const_cast< FtpDirListerOperation*>(this));
    return QObject::qt_metacast(_clname);
}

int FtpDirListerOperation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: started(); break;
        case 1: finished(); break;
        case 2: aborted(); break;
        case 3: loginParamsRequest(); break;
        case 4: execute(); break;
        case 5: abort(); break;
        case 6: listInfo((*reinterpret_cast< const QUrlInfo(*)>(_a[1]))); break;
        case 7: commandStarted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: commandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void FtpDirListerOperation::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void FtpDirListerOperation::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void FtpDirListerOperation::aborted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void FtpDirListerOperation::loginParamsRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
static const uint qt_meta_data_FtpDirLister[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      20,   14,   13,   13, 0x05,
      46,   13,   13,   13, 0x25,
      63,   14,   13,   13, 0x05,
      86,   13,   13,   13, 0x25,
     100,   14,   13,   13, 0x05,
     126,   13,   13,   13, 0x25,
     155,  143,   13,   13, 0x05,
     193,  187,   13,   13, 0x25,
     220,  215,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     256,   13,   13,   13, 0x09,
     279,   13,   13,   13, 0x09,
     303,   13,   13,   13, 0x09,
     326,   13,   13,   13, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_FtpDirLister[] = {
    "FtpDirLister\0\0entry\0listingStarted(FtpEntry*)\0"
    "listingStarted()\0listingDone(FtpEntry*)\0"
    "listingDone()\0listingAborted(FtpEntry*)\0"
    "listingAborted()\0error,entry\0"
    "listingError(QString,FtpEntry*)\0error\0"
    "listingError(QString)\0auth\0"
    "loginParamsRequest(QAuthenticator*)\0"
    "slotOperationStarted()\0slotOperationFinished()\0"
    "slotOperationAborted()\0slotLoginParamsRequest()\0"
};

const QMetaObject FtpDirLister::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FtpDirLister,
      qt_meta_data_FtpDirLister, 0 }
};

const QMetaObject *FtpDirLister::metaObject() const
{
    return &staticMetaObject;
}

void *FtpDirLister::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FtpDirLister))
        return static_cast<void*>(const_cast< FtpDirLister*>(this));
    return QObject::qt_metacast(_clname);
}

int FtpDirLister::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: listingStarted((*reinterpret_cast< FtpEntry*(*)>(_a[1]))); break;
        case 1: listingStarted(); break;
        case 2: listingDone((*reinterpret_cast< FtpEntry*(*)>(_a[1]))); break;
        case 3: listingDone(); break;
        case 4: listingAborted((*reinterpret_cast< FtpEntry*(*)>(_a[1]))); break;
        case 5: listingAborted(); break;
        case 6: listingError((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< FtpEntry*(*)>(_a[2]))); break;
        case 7: listingError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: loginParamsRequest((*reinterpret_cast< QAuthenticator*(*)>(_a[1]))); break;
        case 9: slotOperationStarted(); break;
        case 10: slotOperationFinished(); break;
        case 11: slotOperationAborted(); break;
        case 12: slotLoginParamsRequest(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void FtpDirLister::listingStarted(FtpEntry * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, 1, _a);
}

// SIGNAL 2
void FtpDirLister::listingDone(FtpEntry * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, 3, _a);
}

// SIGNAL 4
void FtpDirLister::listingAborted(FtpEntry * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, 5, _a);
}

// SIGNAL 6
void FtpDirLister::listingError(const QString & _t1, FtpEntry * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, 7, _a);
}

// SIGNAL 8
void FtpDirLister::loginParamsRequest(QAuthenticator * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
