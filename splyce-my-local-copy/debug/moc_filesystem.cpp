/****************************************************************************
** Meta object code from reading C++ file 'filesystem.h'
**
** Created: Sun Dec 6 09:54:31 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../filesystem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filesystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_filesystem[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      64,   12,   11,   11, 0x05,
     129,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     144,   11,   11,   11, 0x0a,
     166,  160,   11,   11, 0x0a,
     197,   11,   11,   11, 0x0a,
     211,   11,   11,   11, 0x0a,
     227,  219,   11,   11, 0x0a,
     259,  247,   11,   11, 0x0a,
     293,   11,   11,   11, 0x0a,
     308,   11,   11,   11, 0x0a,
     341,  325,   11,   11, 0x0a,
     391,  370,   11,   11, 0x0a,
     433,   11,   11,   11, 0x0a,
     446,   11,   11,   11, 0x0a,
     502,  459,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_filesystem[] = {
    "filesystem\0\0"
    "dspFileName,fileName,filePath,originalData,isRemote\0"
    "fileDoubleClickedSignal(QString,QString,QString,QByteArray,bool)\0"
    "sSave2Signal()\0sLocalBrowser()\0index\0"
    "fileDoubleClicked(QModelIndex)\0"
    "sFtpBrowser()\0login()\0urlInfo\0"
    "addToList(QUrlInfo)\0item,column\0"
    "processItem(QTreeWidgetItem*,int)\0"
    "downloadFile()\0cancelDownload()\0"
    "commandId,error\0ftpCommandFinished(int,bool)\0"
    "readBytes,totalBytes\0"
    "updateDataTransferProgress(qint64,qint64)\0"
    "cdToParent()\0disconnect()\0"
    "dspFileName,fileName,modifiedData,isRemote\0"
    "save(QString,QString,QByteArray,bool)\0"
};

const QMetaObject filesystem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_filesystem,
      qt_meta_data_filesystem, 0 }
};

const QMetaObject *filesystem::metaObject() const
{
    return &staticMetaObject;
}

void *filesystem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_filesystem))
        return static_cast<void*>(const_cast< filesystem*>(this));
    return QWidget::qt_metacast(_clname);
}

int filesystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: fileDoubleClickedSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 1: sSave2Signal(); break;
        case 2: sLocalBrowser(); break;
        case 3: fileDoubleClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 4: sFtpBrowser(); break;
        case 5: login(); break;
        case 6: addToList((*reinterpret_cast< const QUrlInfo(*)>(_a[1]))); break;
        case 7: processItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: downloadFile(); break;
        case 9: cancelDownload(); break;
        case 10: ftpCommandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 11: updateDataTransferProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 12: cdToParent(); break;
        case 13: disconnect(); break;
        case 14: save((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void filesystem::fileDoubleClickedSignal(QString _t1, QString _t2, QString _t3, QByteArray _t4, bool _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void filesystem::sSave2Signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
