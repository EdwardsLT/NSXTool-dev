/****************************************************************************
** Meta object code from reading C++ file 'SessionModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../apps/nsxqt/models/SessionModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SessionModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SessionModel_t {
    QByteArrayData data[29];
    char stringdata0[428];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SessionModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SessionModel_t qt_meta_stringdata_SessionModel = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SessionModel"
QT_MOC_LITERAL(1, 13, 13), // "inspectWidget"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "QWidget*"
QT_MOC_LITERAL(4, 37, 17), // "signalUpdatePeaks"
QT_MOC_LITERAL(5, 55, 16), // "signalResetScene"
QT_MOC_LITERAL(6, 72, 25), // "signalSelectedDataChanged"
QT_MOC_LITERAL(7, 98, 16), // "nsx::sptrDataSet"
QT_MOC_LITERAL(8, 115, 5), // "frame"
QT_MOC_LITERAL(9, 121, 24), // "signalChangeSelectedPeak"
QT_MOC_LITERAL(10, 146, 13), // "nsx::sptrPeak"
QT_MOC_LITERAL(11, 160, 4), // "peak"
QT_MOC_LITERAL(12, 165, 24), // "signalEnabledPeakChanged"
QT_MOC_LITERAL(13, 190, 24), // "signalMaskedPeaksChanged"
QT_MOC_LITERAL(14, 215, 4), // "data"
QT_MOC_LITERAL(15, 220, 21), // "signalUnitCellRemoved"
QT_MOC_LITERAL(16, 242, 17), // "nsx::sptrUnitCell"
QT_MOC_LITERAL(17, 260, 9), // "unit_cell"
QT_MOC_LITERAL(18, 270, 20), // "signalChangeColorMap"
QT_MOC_LITERAL(19, 291, 8), // "ColorMap"
QT_MOC_LITERAL(20, 300, 9), // "color_map"
QT_MOC_LITERAL(21, 310, 38), // "signalChangeDetectorViewTrans..."
QT_MOC_LITERAL(22, 349, 14), // "transformation"
QT_MOC_LITERAL(23, 364, 16), // "signalChangePlot"
QT_MOC_LITERAL(24, 381, 7), // "SXPlot*"
QT_MOC_LITERAL(25, 389, 4), // "plot"
QT_MOC_LITERAL(26, 394, 13), // "onItemChanged"
QT_MOC_LITERAL(27, 408, 14), // "QStandardItem*"
QT_MOC_LITERAL(28, 423, 4) // "item"

    },
    "SessionModel\0inspectWidget\0\0QWidget*\0"
    "signalUpdatePeaks\0signalResetScene\0"
    "signalSelectedDataChanged\0nsx::sptrDataSet\0"
    "frame\0signalChangeSelectedPeak\0"
    "nsx::sptrPeak\0peak\0signalEnabledPeakChanged\0"
    "signalMaskedPeaksChanged\0data\0"
    "signalUnitCellRemoved\0nsx::sptrUnitCell\0"
    "unit_cell\0signalChangeColorMap\0ColorMap\0"
    "color_map\0signalChangeDetectorViewTransformation\0"
    "transformation\0signalChangePlot\0SXPlot*\0"
    "plot\0onItemChanged\0QStandardItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SessionModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    0,   77,    2, 0x06 /* Public */,
       5,    0,   78,    2, 0x06 /* Public */,
       6,    2,   79,    2, 0x06 /* Public */,
       9,    1,   84,    2, 0x06 /* Public */,
      12,    1,   87,    2, 0x06 /* Public */,
      13,    1,   90,    2, 0x06 /* Public */,
      15,    1,   93,    2, 0x06 /* Public */,
      18,    1,   96,    2, 0x06 /* Public */,
      21,    1,   99,    2, 0x06 /* Public */,
      23,    1,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      26,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    2,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 7,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, QMetaType::QTransform,   22,
    QMetaType::Void, 0x80000000 | 24,   25,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 27,   28,

       0        // eod
};

void SessionModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SessionModel *_t = static_cast<SessionModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inspectWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->signalUpdatePeaks(); break;
        case 2: _t->signalResetScene(); break;
        case 3: _t->signalSelectedDataChanged((*reinterpret_cast< nsx::sptrDataSet(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->signalChangeSelectedPeak((*reinterpret_cast< nsx::sptrPeak(*)>(_a[1]))); break;
        case 5: _t->signalEnabledPeakChanged((*reinterpret_cast< nsx::sptrPeak(*)>(_a[1]))); break;
        case 6: _t->signalMaskedPeaksChanged((*reinterpret_cast< nsx::sptrDataSet(*)>(_a[1]))); break;
        case 7: _t->signalUnitCellRemoved((*reinterpret_cast< nsx::sptrUnitCell(*)>(_a[1]))); break;
        case 8: _t->signalChangeColorMap((*reinterpret_cast< const ColorMap(*)>(_a[1]))); break;
        case 9: _t->signalChangeDetectorViewTransformation((*reinterpret_cast< const QTransform(*)>(_a[1]))); break;
        case 10: _t->signalChangePlot((*reinterpret_cast< SXPlot*(*)>(_a[1]))); break;
        case 11: _t->onItemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SessionModel::*_t)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SessionModel::inspectWidget)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SessionModel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SessionModel::signalUpdatePeaks)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SessionModel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SessionModel::signalResetScene)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SessionModel::*_t)(nsx::sptrDataSet , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SessionModel::signalSelectedDataChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (SessionModel::*_t)(nsx::sptrPeak );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SessionModel::signalChangeSelectedPeak)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (SessionModel::*_t)(nsx::sptrPeak );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SessionModel::signalEnabledPeakChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (SessionModel::*_t)(nsx::sptrDataSet );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SessionModel::signalMaskedPeaksChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (SessionModel::*_t)(nsx::sptrUnitCell );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SessionModel::signalUnitCellRemoved)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (SessionModel::*_t)(const ColorMap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SessionModel::signalChangeColorMap)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (SessionModel::*_t)(const QTransform & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SessionModel::signalChangeDetectorViewTransformation)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (SessionModel::*_t)(SXPlot * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SessionModel::signalChangePlot)) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject SessionModel::staticMetaObject = {
    { &QStandardItemModel::staticMetaObject, qt_meta_stringdata_SessionModel.data,
      qt_meta_data_SessionModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SessionModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SessionModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SessionModel.stringdata0))
        return static_cast<void*>(this);
    return QStandardItemModel::qt_metacast(_clname);
}

int SessionModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void SessionModel::inspectWidget(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SessionModel::signalUpdatePeaks()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SessionModel::signalResetScene()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SessionModel::signalSelectedDataChanged(nsx::sptrDataSet _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SessionModel::signalChangeSelectedPeak(nsx::sptrPeak _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SessionModel::signalEnabledPeakChanged(nsx::sptrPeak _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SessionModel::signalMaskedPeaksChanged(nsx::sptrDataSet _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SessionModel::signalUnitCellRemoved(nsx::sptrUnitCell _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SessionModel::signalChangeColorMap(const ColorMap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SessionModel::signalChangeDetectorViewTransformation(const QTransform & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void SessionModel::signalChangePlot(SXPlot * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
