/****************************************************************************
** Meta object code from reading C++ file 'FtpDirModel.h'
**
** Created: Tue Oct 20 03:33:37 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FTP/FtpDirModel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FtpDirModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FtpDirModel[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      18,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      60,   54,   12,   12, 0x0a,
      81,   12,   12,   12, 0x2a,
      97,   91,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FtpDirModel[] = {
    "FtpDirModel\0\0auth\0loginParamsRequest(QAuthenticator*)\0"
    "index\0refresh(QModelIndex)\0refresh()\0"
    "entry\0slotListingDone(FtpEntry*)\0"
};

const QMetaObject FtpDirModel::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_FtpDirModel,
      qt_meta_data_FtpDirModel, 0 }
};

const QMetaObject *FtpDirModel::metaObject() const
{
    return &staticMetaObject;
}

void *FtpDirModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FtpDirModel))
        return static_cast<void*>(const_cast< FtpDirModel*>(this));
    return QAbstractItemModel::qt_metacast(_clname);
}

int FtpDirModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loginParamsRequest((*reinterpret_cast< QAuthenticator*(*)>(_a[1]))); break;
        case 1: refresh((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: refresh(); break;
        case 3: slotListingDone((*reinterpret_cast< FtpEntry*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void FtpDirModel::loginParamsRequest(QAuthenticator * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
