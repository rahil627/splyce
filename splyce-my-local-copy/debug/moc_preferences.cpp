/****************************************************************************
** Meta object code from reading C++ file 'preferences.h'
**
** Created: Sun Nov 29 19:38:26 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../preferences.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'preferences.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_preferences[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      21,   12,   12,   12, 0x0a,
      28,   12,   12,   12, 0x0a,
      41,   12,   12,   12, 0x0a,
      50,   12,   12,   12, 0x0a,
      61,   12,   12,   12, 0x0a,
      71,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_preferences[] = {
    "preferences\0\0sFont()\0sTag()\0sAttribute()\0"
    "sQuote()\0sComment()\0sEntity()\0sAccept()\0"
};

const QMetaObject preferences::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_preferences,
      qt_meta_data_preferences, 0 }
};

const QMetaObject *preferences::metaObject() const
{
    return &staticMetaObject;
}

void *preferences::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_preferences))
        return static_cast<void*>(const_cast< preferences*>(this));
    return QDialog::qt_metacast(_clname);
}

int preferences::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sFont(); break;
        case 1: sTag(); break;
        case 2: sAttribute(); break;
        case 3: sQuote(); break;
        case 4: sComment(); break;
        case 5: sEntity(); break;
        case 6: sAccept(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
