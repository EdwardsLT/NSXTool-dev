/****************************************************************************
** Meta object code from reading C++ file 'UnitCellPropertyWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../apps/nsxqt/tree/UnitCellPropertyWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UnitCellPropertyWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UnitCellPropertyWidget_t {
    QByteArrayData data[16];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UnitCellPropertyWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UnitCellPropertyWidget_t qt_meta_stringdata_UnitCellPropertyWidget = {
    {
QT_MOC_LITERAL(0, 0, 22), // "UnitCellPropertyWidget"
QT_MOC_LITERAL(1, 23, 15), // "setUnitCellName"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 16), // "getLatticeParams"
QT_MOC_LITERAL(4, 57, 16), // "setLatticeParams"
QT_MOC_LITERAL(5, 74, 18), // "setChemicalFormula"
QT_MOC_LITERAL(6, 93, 13), // "setSpaceGroup"
QT_MOC_LITERAL(7, 107, 2), // "sg"
QT_MOC_LITERAL(8, 110, 9), // "setZValue"
QT_MOC_LITERAL(9, 120, 1), // "z"
QT_MOC_LITERAL(10, 122, 14), // "setMassDensity"
QT_MOC_LITERAL(11, 137, 28), // "activateSpaceGroupCompletion"
QT_MOC_LITERAL(12, 166, 20), // "setIndexingTolerance"
QT_MOC_LITERAL(13, 187, 6), // "update"
QT_MOC_LITERAL(14, 194, 14), // "QStandardItem*"
QT_MOC_LITERAL(15, 209, 4) // "item"

    },
    "UnitCellPropertyWidget\0setUnitCellName\0"
    "\0getLatticeParams\0setLatticeParams\0"
    "setChemicalFormula\0setSpaceGroup\0sg\0"
    "setZValue\0z\0setMassDensity\0"
    "activateSpaceGroupCompletion\0"
    "setIndexingTolerance\0update\0QStandardItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UnitCellPropertyWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    1,   73,    2, 0x08 /* Private */,
       8,    1,   76,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    1,   80,    2, 0x08 /* Private */,
      12,    1,   83,    2, 0x08 /* Private */,
      13,    1,   86,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x28 /* Private | MethodCloned */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,

       0        // eod
};

void UnitCellPropertyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UnitCellPropertyWidget *_t = static_cast<UnitCellPropertyWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setUnitCellName(); break;
        case 1: _t->getLatticeParams(); break;
        case 2: _t->setLatticeParams(); break;
        case 3: _t->setChemicalFormula(); break;
        case 4: _t->setSpaceGroup((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setZValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setMassDensity(); break;
        case 7: _t->activateSpaceGroupCompletion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setIndexingTolerance((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->update((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 10: _t->update(); break;
        default: ;
        }
    }
}

const QMetaObject UnitCellPropertyWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UnitCellPropertyWidget.data,
      qt_meta_data_UnitCellPropertyWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UnitCellPropertyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UnitCellPropertyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UnitCellPropertyWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UnitCellPropertyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
