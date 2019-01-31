/****************************************************************************
** Meta object code from reading C++ file 'FramePeakFinder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../apps/nsxqt/frames/FramePeakFinder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FramePeakFinder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FramePeakFinder_t {
    QByteArrayData data[29];
    char stringdata0[411];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FramePeakFinder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FramePeakFinder_t qt_meta_stringdata_FramePeakFinder = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FramePeakFinder"
QT_MOC_LITERAL(1, 16, 16), // "onChangeColorMap"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 8), // "ColorMap"
QT_MOC_LITERAL(4, 43, 4), // "name"
QT_MOC_LITERAL(5, 48, 17), // "changeMaxBlobSize"
QT_MOC_LITERAL(6, 66, 17), // "changeMinBlobSize"
QT_MOC_LITERAL(7, 84, 15), // "changePeakScale"
QT_MOC_LITERAL(8, 100, 21), // "changeBackgroundBegin"
QT_MOC_LITERAL(9, 122, 19), // "changeBackgroundEnd"
QT_MOC_LITERAL(10, 142, 9), // "doActions"
QT_MOC_LITERAL(11, 152, 16), // "QAbstractButton*"
QT_MOC_LITERAL(12, 169, 6), // "button"
QT_MOC_LITERAL(13, 176, 17), // "changePreviewData"
QT_MOC_LITERAL(14, 194, 23), // "changeConvolutionKernel"
QT_MOC_LITERAL(15, 218, 18), // "convolution_kernel"
QT_MOC_LITERAL(16, 237, 27), // "changeConvolutionParameters"
QT_MOC_LITERAL(17, 265, 3), // "row"
QT_MOC_LITERAL(18, 269, 3), // "col"
QT_MOC_LITERAL(19, 273, 11), // "clipPreview"
QT_MOC_LITERAL(20, 285, 5), // "state"
QT_MOC_LITERAL(21, 291, 19), // "changeSelectedFrame"
QT_MOC_LITERAL(22, 311, 14), // "selected_frame"
QT_MOC_LITERAL(23, 326, 13), // "slotTabEdited"
QT_MOC_LITERAL(24, 340, 5), // "index"
QT_MOC_LITERAL(25, 346, 14), // "slotTabRemoved"
QT_MOC_LITERAL(26, 361, 16), // "onShowFoundPeaks"
QT_MOC_LITERAL(27, 378, 27), // "std::shared_ptr<nsx::ITask>"
QT_MOC_LITERAL(28, 406, 4) // "task"

    },
    "FramePeakFinder\0onChangeColorMap\0\0"
    "ColorMap\0name\0changeMaxBlobSize\0"
    "changeMinBlobSize\0changePeakScale\0"
    "changeBackgroundBegin\0changeBackgroundEnd\0"
    "doActions\0QAbstractButton*\0button\0"
    "changePreviewData\0changeConvolutionKernel\0"
    "convolution_kernel\0changeConvolutionParameters\0"
    "row\0col\0clipPreview\0state\0changeSelectedFrame\0"
    "selected_frame\0slotTabEdited\0index\0"
    "slotTabRemoved\0onShowFoundPeaks\0"
    "std::shared_ptr<nsx::ITask>\0task"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FramePeakFinder[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    1,   97,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    1,  101,    2, 0x08 /* Private */,
      16,    2,  104,    2, 0x08 /* Private */,
      19,    1,  109,    2, 0x08 /* Private */,
      21,    1,  112,    2, 0x08 /* Private */,
      23,    1,  115,    2, 0x08 /* Private */,
      25,    1,  118,    2, 0x08 /* Private */,
      26,    1,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, 0x80000000 | 27,   28,

       0        // eod
};

void FramePeakFinder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FramePeakFinder *_t = static_cast<FramePeakFinder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onChangeColorMap((*reinterpret_cast< const ColorMap(*)>(_a[1]))); break;
        case 1: _t->changeMaxBlobSize(); break;
        case 2: _t->changeMinBlobSize(); break;
        case 3: _t->changePeakScale(); break;
        case 4: _t->changeBackgroundBegin(); break;
        case 5: _t->changeBackgroundEnd(); break;
        case 6: _t->doActions((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 7: _t->changePreviewData(); break;
        case 8: _t->changeConvolutionKernel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->changeConvolutionParameters((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->clipPreview((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->changeSelectedFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->slotTabEdited((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->slotTabRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->onShowFoundPeaks((*reinterpret_cast< std::shared_ptr<nsx::ITask>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject FramePeakFinder::staticMetaObject = {
    { &NSXQFrame::staticMetaObject, qt_meta_stringdata_FramePeakFinder.data,
      qt_meta_data_FramePeakFinder,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FramePeakFinder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FramePeakFinder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FramePeakFinder.stringdata0))
        return static_cast<void*>(this);
    return NSXQFrame::qt_metacast(_clname);
}

int FramePeakFinder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NSXQFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
