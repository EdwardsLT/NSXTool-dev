/****************************************************************************
** Meta object code from reading C++ file 'SXPlot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../apps/nsxqt/plot/SXPlot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SXPlot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SXPlot_t {
    QByteArrayData data[16];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SXPlot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SXPlot_t qt_meta_stringdata_SXPlot = {
    {
QT_MOC_LITERAL(0, 0, 6), // "SXPlot"
QT_MOC_LITERAL(1, 7, 10), // "mousePress"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 10), // "mouseWheel"
QT_MOC_LITERAL(4, 30, 16), // "titleDoubleClick"
QT_MOC_LITERAL(5, 47, 12), // "QMouseEvent*"
QT_MOC_LITERAL(6, 60, 5), // "event"
QT_MOC_LITERAL(7, 66, 13), // "QCPPlotTitle*"
QT_MOC_LITERAL(8, 80, 5), // "title"
QT_MOC_LITERAL(9, 86, 17), // "legendDoubleClick"
QT_MOC_LITERAL(10, 104, 10), // "QCPLegend*"
QT_MOC_LITERAL(11, 115, 6), // "legend"
QT_MOC_LITERAL(12, 122, 22), // "QCPAbstractLegendItem*"
QT_MOC_LITERAL(13, 145, 4), // "item"
QT_MOC_LITERAL(14, 150, 16), // "setmenuRequested"
QT_MOC_LITERAL(15, 167, 13) // "exportToAscii"

    },
    "SXPlot\0mousePress\0\0mouseWheel\0"
    "titleDoubleClick\0QMouseEvent*\0event\0"
    "QCPPlotTitle*\0title\0legendDoubleClick\0"
    "QCPLegend*\0legend\0QCPAbstractLegendItem*\0"
    "item\0setmenuRequested\0exportToAscii"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SXPlot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    2,   46,    2, 0x0a /* Public */,
       9,    2,   51,    2, 0x0a /* Public */,
      14,    1,   56,    2, 0x0a /* Public */,
      15,    0,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 12,   11,   13,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,

       0        // eod
};

void SXPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SXPlot *_t = static_cast<SXPlot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mousePress(); break;
        case 1: _t->mouseWheel(); break;
        case 2: _t->titleDoubleClick((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< QCPPlotTitle*(*)>(_a[2]))); break;
        case 3: _t->legendDoubleClick((*reinterpret_cast< QCPLegend*(*)>(_a[1])),(*reinterpret_cast< QCPAbstractLegendItem*(*)>(_a[2]))); break;
        case 4: _t->setmenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->exportToAscii(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPPlotTitle* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAbstractLegendItem* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPLegend* >(); break;
            }
            break;
        }
    }
}

const QMetaObject SXPlot::staticMetaObject = {
    { &QCustomPlot::staticMetaObject, qt_meta_stringdata_SXPlot.data,
      qt_meta_data_SXPlot,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SXPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SXPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SXPlot.stringdata0))
        return static_cast<void*>(this);
    return QCustomPlot::qt_metacast(_clname);
}

int SXPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCustomPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
