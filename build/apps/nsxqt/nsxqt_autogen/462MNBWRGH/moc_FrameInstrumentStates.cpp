/****************************************************************************
** Meta object code from reading C++ file 'FrameInstrumentStates.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../apps/nsxqt/frames/FrameInstrumentStates.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrameInstrumentStates.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrameInstrumentStates_t {
    QByteArrayData data[9];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrameInstrumentStates_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrameInstrumentStates_t qt_meta_stringdata_FrameInstrumentStates = {
    {
QT_MOC_LITERAL(0, 0, 21), // "FrameInstrumentStates"
QT_MOC_LITERAL(1, 22, 17), // "slotActionClicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 16), // "QAbstractButton*"
QT_MOC_LITERAL(4, 58, 6), // "button"
QT_MOC_LITERAL(5, 65, 23), // "slotSelectedDataChanged"
QT_MOC_LITERAL(6, 89, 13), // "selected_data"
QT_MOC_LITERAL(7, 103, 24), // "slotSelectedFrameChanged"
QT_MOC_LITERAL(8, 128, 14) // "selected_frame"

    },
    "FrameInstrumentStates\0slotActionClicked\0"
    "\0QAbstractButton*\0button\0"
    "slotSelectedDataChanged\0selected_data\0"
    "slotSelectedFrameChanged\0selected_frame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrameInstrumentStates[] = {

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
       1,    1,   29,    2, 0x08 /* Private */,
       5,    1,   32,    2, 0x08 /* Private */,
       7,    1,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void FrameInstrumentStates::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FrameInstrumentStates *_t = static_cast<FrameInstrumentStates *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotActionClicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 1: _t->slotSelectedDataChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slotSelectedFrameChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject FrameInstrumentStates::staticMetaObject = {
    { &NSXQFrame::staticMetaObject, qt_meta_stringdata_FrameInstrumentStates.data,
      qt_meta_data_FrameInstrumentStates,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FrameInstrumentStates::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrameInstrumentStates::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrameInstrumentStates.stringdata0))
        return static_cast<void*>(this);
    return NSXQFrame::qt_metacast(_clname);
}

int FrameInstrumentStates::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NSXQFrame::qt_metacall(_c, _id, _a);
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
