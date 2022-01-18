/****************************************************************************
** Meta object code from reading C++ file 'workbench.h'
**
** Created: Sun Dec 6 09:54:30 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../workbench.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workbench.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_workbench[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      32,   28,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      77,   10,   10,   10, 0x0a,
     136,   84,   10,   10, 0x0a,
     195,  182,   10,   10, 0x0a,
     209,   10,   10,   10, 0x0a,
     217,   10,   10,   10, 0x0a,
     225,   10,   10,   10, 0x0a,
     234,   10,   10,   10, 0x0a,
     244,   10,   10,   10, 0x0a,
     261,   10,   10,   10, 0x0a,
     270,   10,   10,   10, 0x0a,
     284,   10,   10,   10, 0x0a,
     295,   10,   10,   10, 0x0a,
     303,   10,   10,   10, 0x0a,
     318,   10,   10,   10, 0x0a,
     326,   10,   10,   10, 0x0a,
     334,   10,   10,   10, 0x0a,
     341,   10,   10,   10, 0x0a,
     349,   10,   10,   10, 0x0a,
     358,   10,   10,   10, 0x0a,
     366,   10,   10,   10, 0x0a,
     378,   10,   10,   10, 0x0a,
     386,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_workbench[] = {
    "workbench\0\0currentChanged()\0,,,\0"
    "sSaveSignal(QString,QString,QByteArray,bool)\0"
    "sNew()\0dspFileName,fileName,filePath,originalData,isRemote\0"
    "sNew(QString,QString,QString,QByteArray,bool)\0"
    "tempFileName\0sNew(QString)\0sOpen()\0"
    "sSave()\0sSave2()\0sSaveAs()\0sCloseFunction()\0"
    "sClose()\0sFilesystem()\0sPreview()\0"
    "sEdit()\0sPreferences()\0sUndo()\0sRedo()\0"
    "sCut()\0sCopy()\0sPaste()\0sNext()\0"
    "sPrevious()\0sSync()\0sCurrentChanged()\0"
};

const QMetaObject workbench::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_workbench,
      qt_meta_data_workbench, 0 }
};

const QMetaObject *workbench::metaObject() const
{
    return &staticMetaObject;
}

void *workbench::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_workbench))
        return static_cast<void*>(const_cast< workbench*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int workbench::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: currentChanged(); break;
        case 1: sSaveSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 2: sNew(); break;
        case 3: sNew((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 4: sNew((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: sOpen(); break;
        case 6: sSave(); break;
        case 7: sSave2(); break;
        case 8: sSaveAs(); break;
        case 9: sCloseFunction(); break;
        case 10: sClose(); break;
        case 11: sFilesystem(); break;
        case 12: sPreview(); break;
        case 13: sEdit(); break;
        case 14: sPreferences(); break;
        case 15: sUndo(); break;
        case 16: sRedo(); break;
        case 17: sCut(); break;
        case 18: sCopy(); break;
        case 19: sPaste(); break;
        case 20: sNext(); break;
        case 21: sPrevious(); break;
        case 22: sSync(); break;
        case 23: sCurrentChanged(); break;
        default: ;
        }
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void workbench::currentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void workbench::sSaveSignal(QString _t1, QString _t2, QByteArray _t3, bool _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
