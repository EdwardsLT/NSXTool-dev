/****************************************************************************
** Meta object code from reading C++ file 'FrameUserDefinedUnitCellIndexer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../apps/nsxqt/frames/FrameUserDefinedUnitCellIndexer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrameUserDefinedUnitCellIndexer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrameUserDefinedUnitCellIndexer_t {
    QByteArrayData data[9];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrameUserDefinedUnitCellIndexer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrameUserDefinedUnitCellIndexer_t qt_meta_stringdata_FrameUserDefinedUnitCellIndexer = {
    {
QT_MOC_LITERAL(0, 0, 31), // "FrameUserDefinedUnitCellIndexer"
QT_MOC_LITERAL(1, 32, 17), // "slotActionClicked"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 16), // "QAbstractButton*"
QT_MOC_LITERAL(4, 68, 6), // "button"
QT_MOC_LITERAL(5, 75, 13), // "slotTabEdited"
QT_MOC_LITERAL(6, 89, 5), // "index"
QT_MOC_LITERAL(7, 95, 14), // "slotTabRemoved"
QT_MOC_LITERAL(8, 110, 18) // "slotSelectSolution"

    },
    "FrameUserDefinedUnitCellIndexer\0"
    "slotActionClicked\0\0QAbstractButton*\0"
    "button\0slotTabEdited\0index\0slotTabRemoved\0"
    "slotSelectSolution"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrameUserDefinedUnitCellIndexer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,
       7,    1,   40,    2, 0x08 /* Private */,
       8,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void FrameUserDefinedUnitCellIndexer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FrameUserDefinedUnitCellIndexer *_t = static_cast<FrameUserDefinedUnitCellIndexer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotActionClicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 1: _t->slotTabEdited((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slotTabRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slotSelectSolution((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject FrameUserDefinedUnitCellIndexer::staticMetaObject = {
    { &NSXQFrame::staticMetaObject, qt_meta_stringdata_FrameUserDefinedUnitCellIndexer.data,
      qt_meta_data_FrameUserDefinedUnitCellIndexer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FrameUserDefinedUnitCellIndexer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrameUserDefinedUnitCellIndexer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrameUserDefinedUnitCellIndexer.stringdata0))
        return static_cast<void*>(this);
    return NSXQFrame::qt_metacast(_clname);
}

int FrameUserDefinedUnitCellIndexer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NSXQFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
