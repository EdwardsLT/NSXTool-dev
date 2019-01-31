/****************************************************************************
** Meta object code from reading C++ file 'NoteBook.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../apps/nsxqt/NoteBook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NoteBook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NoteBook_t {
    QByteArrayData data[8];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NoteBook_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NoteBook_t qt_meta_stringdata_NoteBook = {
    {
QT_MOC_LITERAL(0, 0, 8), // "NoteBook"
QT_MOC_LITERAL(1, 9, 15), // "printLogMessage"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "std::string"
QT_MOC_LITERAL(4, 38, 7), // "message"
QT_MOC_LITERAL(5, 46, 19), // "customMenuRequested"
QT_MOC_LITERAL(6, 66, 3), // "pos"
QT_MOC_LITERAL(7, 70, 9) // "write2pdf"

    },
    "NoteBook\0printLogMessage\0\0std::string\0"
    "message\0customMenuRequested\0pos\0"
    "write2pdf"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NoteBook[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    1,   32,    2, 0x0a /* Public */,
       7,    0,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void,

       0        // eod
};

void NoteBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NoteBook *_t = static_cast<NoteBook *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->printLogMessage((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 1: _t->customMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->write2pdf(); break;
        default: ;
        }
    }
}

const QMetaObject NoteBook::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_NoteBook.data,
      qt_meta_data_NoteBook,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *NoteBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NoteBook::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NoteBook.stringdata0))
        return static_cast<void*>(this);
    return QTextEdit::qt_metacast(_clname);
}

int NoteBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
