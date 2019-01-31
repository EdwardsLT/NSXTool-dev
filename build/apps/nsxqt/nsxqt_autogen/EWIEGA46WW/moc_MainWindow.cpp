/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../apps/nsxqt/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "onChangeContrastLevel"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 14), // "contrast_level"
QT_MOC_LITERAL(4, 49, 20), // "onChangeSelectedData"
QT_MOC_LITERAL(5, 70, 16), // "nsx::sptrDataSet"
QT_MOC_LITERAL(6, 87, 5), // "frame"
QT_MOC_LITERAL(7, 93, 21), // "onChangeSelectedFrame"
QT_MOC_LITERAL(8, 115, 14), // "selected_frame"
QT_MOC_LITERAL(9, 130, 34), // "onDisplaySessionItemPropertyW..."
QT_MOC_LITERAL(10, 165, 8), // "QWidget*"
QT_MOC_LITERAL(11, 174, 15), // "onNewExperiment"
QT_MOC_LITERAL(12, 190, 12), // "onChangePlot"
QT_MOC_LITERAL(13, 203, 7), // "SXPlot*"
QT_MOC_LITERAL(14, 211, 4), // "plot"
QT_MOC_LITERAL(15, 216, 20), // "onChangeSelectedPeak"
QT_MOC_LITERAL(16, 237, 13), // "nsx::sptrPeak"
QT_MOC_LITERAL(17, 251, 13) // "selected_peak"

    },
    "MainWindow\0onChangeContrastLevel\0\0"
    "contrast_level\0onChangeSelectedData\0"
    "nsx::sptrDataSet\0frame\0onChangeSelectedFrame\0"
    "selected_frame\0onDisplaySessionItemPropertyWidget\0"
    "QWidget*\0onNewExperiment\0onChangePlot\0"
    "SXPlot*\0plot\0onChangeSelectedPeak\0"
    "nsx::sptrPeak\0selected_peak"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    2,   52,    2, 0x0a /* Public */,
       7,    1,   57,    2, 0x0a /* Public */,
       9,    1,   60,    2, 0x0a /* Public */,
      11,    0,   63,    2, 0x0a /* Public */,
      12,    1,   64,    2, 0x0a /* Public */,
      15,    1,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    2,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onChangeContrastLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onChangeSelectedData((*reinterpret_cast< nsx::sptrDataSet(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->onChangeSelectedFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onDisplaySessionItemPropertyWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 4: _t->onNewExperiment(); break;
        case 5: _t->onChangePlot((*reinterpret_cast< SXPlot*(*)>(_a[1]))); break;
        case 6: _t->onChangeSelectedPeak((*reinterpret_cast< nsx::sptrPeak(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
