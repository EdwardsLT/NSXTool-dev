/****************************************************************************
** Meta object code from reading C++ file 'DialogAbsorption.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../apps/nsxqt/dialogs/DialogAbsorption.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogAbsorption.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogAbsorption_t {
    QByteArrayData data[13];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogAbsorption_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogAbsorption_t qt_meta_stringdata_DialogAbsorption = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DialogAbsorption"
QT_MOC_LITERAL(1, 17, 9), // "loadImage"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "image"
QT_MOC_LITERAL(4, 34, 9), // "angleText"
QT_MOC_LITERAL(5, 44, 4), // "text"
QT_MOC_LITERAL(6, 49, 10), // "exportHull"
QT_MOC_LITERAL(7, 60, 15), // "nsx::ConvexHull"
QT_MOC_LITERAL(8, 76, 4), // "hull"
QT_MOC_LITERAL(9, 81, 16), // "initializeSlider"
QT_MOC_LITERAL(10, 98, 1), // "i"
QT_MOC_LITERAL(11, 100, 26), // "on_button_openFile_pressed"
QT_MOC_LITERAL(12, 127, 19) // "setupInitialButtons"

    },
    "DialogAbsorption\0loadImage\0\0image\0"
    "angleText\0text\0exportHull\0nsx::ConvexHull\0"
    "hull\0initializeSlider\0i\0"
    "on_button_openFile_pressed\0"
    "setupInitialButtons"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogAbsorption[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   53,    2, 0x0a /* Public */,
      11,    0,   56,    2, 0x08 /* Private */,
      12,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogAbsorption::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogAbsorption *_t = static_cast<DialogAbsorption *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->angleText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->exportHull((*reinterpret_cast< const nsx::ConvexHull(*)>(_a[1]))); break;
        case 3: _t->initializeSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_button_openFile_pressed(); break;
        case 5: _t->setupInitialButtons(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DialogAbsorption::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogAbsorption::loadImage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DialogAbsorption::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogAbsorption::angleText)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DialogAbsorption::*_t)(const nsx::ConvexHull & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogAbsorption::exportHull)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject DialogAbsorption::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogAbsorption.data,
      qt_meta_data_DialogAbsorption,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DialogAbsorption::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogAbsorption::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogAbsorption.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogAbsorption::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void DialogAbsorption::loadImage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DialogAbsorption::angleText(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DialogAbsorption::exportHull(const nsx::ConvexHull & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
