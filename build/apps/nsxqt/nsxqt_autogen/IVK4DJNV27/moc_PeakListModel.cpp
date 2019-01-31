/****************************************************************************
** Meta object code from reading C++ file 'PeakListModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../apps/nsxqt/models/PeakListModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PeakListModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PeakListModel_t {
    QByteArrayData data[17];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PeakListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PeakListModel_t qt_meta_stringdata_PeakListModel = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PeakListModel"
QT_MOC_LITERAL(1, 14, 15), // "unitCellUpdated"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 21), // "slotChangeEnabledPeak"
QT_MOC_LITERAL(4, 53, 13), // "nsx::sptrPeak"
QT_MOC_LITERAL(5, 67, 4), // "peak"
QT_MOC_LITERAL(6, 72, 21), // "slotChangeMaskedPeaks"
QT_MOC_LITERAL(7, 94, 16), // "nsx::sptrDataSet"
QT_MOC_LITERAL(8, 111, 4), // "data"
QT_MOC_LITERAL(9, 116, 18), // "slotRemoveUnitCell"
QT_MOC_LITERAL(10, 135, 17), // "nsx::sptrUnitCell"
QT_MOC_LITERAL(11, 153, 9), // "unit_cell"
QT_MOC_LITERAL(12, 163, 11), // "setUnitCell"
QT_MOC_LITERAL(13, 175, 8), // "unitCell"
QT_MOC_LITERAL(14, 184, 15), // "QModelIndexList"
QT_MOC_LITERAL(15, 200, 13), // "selectedPeaks"
QT_MOC_LITERAL(16, 214, 15) // "sortEquivalents"

    },
    "PeakListModel\0unitCellUpdated\0\0"
    "slotChangeEnabledPeak\0nsx::sptrPeak\0"
    "peak\0slotChangeMaskedPeaks\0nsx::sptrDataSet\0"
    "data\0slotRemoveUnitCell\0nsx::sptrUnitCell\0"
    "unit_cell\0setUnitCell\0unitCell\0"
    "QModelIndexList\0selectedPeaks\0"
    "sortEquivalents"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PeakListModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   50,    2, 0x0a /* Public */,
       6,    1,   53,    2, 0x0a /* Public */,
       9,    1,   56,    2, 0x0a /* Public */,
      12,    2,   59,    2, 0x0a /* Public */,
      12,    1,   64,    2, 0x2a /* Public | MethodCloned */,
      16,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 14,   13,   15,
    QMetaType::Void, 0x80000000 | 10,   13,
    QMetaType::Void,

       0        // eod
};

void PeakListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PeakListModel *_t = static_cast<PeakListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->unitCellUpdated(); break;
        case 1: _t->slotChangeEnabledPeak((*reinterpret_cast< nsx::sptrPeak(*)>(_a[1]))); break;
        case 2: _t->slotChangeMaskedPeaks((*reinterpret_cast< nsx::sptrDataSet(*)>(_a[1]))); break;
        case 3: _t->slotRemoveUnitCell((*reinterpret_cast< const nsx::sptrUnitCell(*)>(_a[1]))); break;
        case 4: _t->setUnitCell((*reinterpret_cast< const nsx::sptrUnitCell(*)>(_a[1])),(*reinterpret_cast< QModelIndexList(*)>(_a[2]))); break;
        case 5: _t->setUnitCell((*reinterpret_cast< const nsx::sptrUnitCell(*)>(_a[1]))); break;
        case 6: _t->sortEquivalents(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QModelIndexList >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PeakListModel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeakListModel::unitCellUpdated)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PeakListModel::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_PeakListModel.data,
      qt_meta_data_PeakListModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PeakListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PeakListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PeakListModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int PeakListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void PeakListModel::unitCellUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
