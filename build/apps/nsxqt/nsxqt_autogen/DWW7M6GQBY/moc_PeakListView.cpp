/****************************************************************************
** Meta object code from reading C++ file 'PeakListView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../apps/nsxqt/views/PeakListView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PeakListView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PeakListView_t {
    QByteArrayData data[21];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PeakListView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PeakListView_t qt_meta_stringdata_PeakListView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PeakListView"
QT_MOC_LITERAL(1, 13, 8), // "plotData"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 39, 8), // "plotPeak"
QT_MOC_LITERAL(5, 48, 13), // "nsx::sptrPeak"
QT_MOC_LITERAL(6, 62, 11), // "autoIndexed"
QT_MOC_LITERAL(7, 74, 18), // "updateShapeLibrary"
QT_MOC_LITERAL(8, 93, 21), // "nsx::sptrShapeLibrary"
QT_MOC_LITERAL(9, 115, 18), // "normalizeToMonitor"
QT_MOC_LITERAL(10, 134, 6), // "plotAs"
QT_MOC_LITERAL(11, 141, 11), // "std::string"
QT_MOC_LITERAL(12, 153, 3), // "key"
QT_MOC_LITERAL(13, 157, 10), // "selectPeak"
QT_MOC_LITERAL(14, 168, 5), // "index"
QT_MOC_LITERAL(15, 174, 18), // "clearSelectedPeaks"
QT_MOC_LITERAL(16, 193, 14), // "selectAllPeaks"
QT_MOC_LITERAL(17, 208, 16), // "selectValidPeaks"
QT_MOC_LITERAL(18, 225, 20), // "selectUnindexedPeaks"
QT_MOC_LITERAL(19, 246, 20), // "togglePeaksSelection"
QT_MOC_LITERAL(20, 267, 19) // "togglePeakSelection"

    },
    "PeakListView\0plotData\0\0QVector<double>\0"
    "plotPeak\0nsx::sptrPeak\0autoIndexed\0"
    "updateShapeLibrary\0nsx::sptrShapeLibrary\0"
    "normalizeToMonitor\0plotAs\0std::string\0"
    "key\0selectPeak\0index\0clearSelectedPeaks\0"
    "selectAllPeaks\0selectValidPeaks\0"
    "selectUnindexedPeaks\0togglePeaksSelection\0"
    "togglePeakSelection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PeakListView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   79,    2, 0x06 /* Public */,
       4,    1,   86,    2, 0x06 /* Public */,
       6,    0,   89,    2, 0x06 /* Public */,
       7,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   93,    2, 0x0a /* Public */,
      10,    1,   94,    2, 0x0a /* Public */,
      13,    1,   97,    2, 0x0a /* Public */,
      15,    0,  100,    2, 0x0a /* Public */,
      16,    0,  101,    2, 0x0a /* Public */,
      17,    0,  102,    2, 0x0a /* Public */,
      18,    0,  103,    2, 0x0a /* Public */,
      19,    0,  104,    2, 0x0a /* Public */,
      20,    1,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QModelIndex,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   14,

       0        // eod
};

void PeakListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PeakListView *_t = static_cast<PeakListView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->plotData((*reinterpret_cast< const QVector<double>(*)>(_a[1])),(*reinterpret_cast< const QVector<double>(*)>(_a[2])),(*reinterpret_cast< const QVector<double>(*)>(_a[3]))); break;
        case 1: _t->plotPeak((*reinterpret_cast< nsx::sptrPeak(*)>(_a[1]))); break;
        case 2: _t->autoIndexed(); break;
        case 3: _t->updateShapeLibrary((*reinterpret_cast< nsx::sptrShapeLibrary(*)>(_a[1]))); break;
        case 4: _t->normalizeToMonitor(); break;
        case 5: _t->plotAs((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 6: _t->selectPeak((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 7: _t->clearSelectedPeaks(); break;
        case 8: _t->selectAllPeaks(); break;
        case 9: _t->selectValidPeaks(); break;
        case 10: _t->selectUnindexedPeaks(); break;
        case 11: _t->togglePeaksSelection(); break;
        case 12: _t->togglePeakSelection((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PeakListView::*_t)(const QVector<double> & , const QVector<double> & , const QVector<double> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeakListView::plotData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PeakListView::*_t)(nsx::sptrPeak );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeakListView::plotPeak)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PeakListView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeakListView::autoIndexed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PeakListView::*_t)(nsx::sptrShapeLibrary );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeakListView::updateShapeLibrary)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject PeakListView::staticMetaObject = {
    { &QTableView::staticMetaObject, qt_meta_stringdata_PeakListView.data,
      qt_meta_data_PeakListView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PeakListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PeakListView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PeakListView.stringdata0))
        return static_cast<void*>(this);
    return QTableView::qt_metacast(_clname);
}

int PeakListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void PeakListView::plotData(const QVector<double> & _t1, const QVector<double> & _t2, const QVector<double> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PeakListView::plotPeak(nsx::sptrPeak _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PeakListView::autoIndexed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PeakListView::updateShapeLibrary(nsx::sptrShapeLibrary _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
