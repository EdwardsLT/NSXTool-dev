/****************************************************************************
** Meta object code from reading C++ file 'CrystalScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../apps/nsxqt/models/CrystalScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CrystalScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CrystalScene_t {
    QByteArrayData data[23];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CrystalScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CrystalScene_t qt_meta_stringdata_CrystalScene = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CrystalScene"
QT_MOC_LITERAL(1, 13, 19), // "calibrateDistanceOK"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "npixels"
QT_MOC_LITERAL(4, 42, 8), // "distance"
QT_MOC_LITERAL(5, 51, 17), // "calibrateCenterOK"
QT_MOC_LITERAL(6, 69, 1), // "x"
QT_MOC_LITERAL(7, 71, 1), // "y"
QT_MOC_LITERAL(8, 73, 9), // "loadImage"
QT_MOC_LITERAL(9, 83, 8), // "filename"
QT_MOC_LITERAL(10, 92, 8), // "drawText"
QT_MOC_LITERAL(11, 101, 4), // "text"
QT_MOC_LITERAL(12, 106, 25), // "activateCalibrateDistance"
QT_MOC_LITERAL(13, 132, 18), // "activatePickCenter"
QT_MOC_LITERAL(14, 151, 21), // "activatePickingPoints"
QT_MOC_LITERAL(15, 173, 22), // "activateRemovingPoints"
QT_MOC_LITERAL(16, 196, 11), // "getDistance"
QT_MOC_LITERAL(17, 208, 3), // "val"
QT_MOC_LITERAL(18, 212, 10), // "stampScale"
QT_MOC_LITERAL(19, 223, 16), // "setRotationAngle"
QT_MOC_LITERAL(20, 240, 11), // "triangulate"
QT_MOC_LITERAL(21, 252, 16), // "changeBrigthness"
QT_MOC_LITERAL(22, 269, 1) // "a"

    },
    "CrystalScene\0calibrateDistanceOK\0\0"
    "npixels\0distance\0calibrateCenterOK\0x\0"
    "y\0loadImage\0filename\0drawText\0text\0"
    "activateCalibrateDistance\0activatePickCenter\0"
    "activatePickingPoints\0activateRemovingPoints\0"
    "getDistance\0val\0stampScale\0setRotationAngle\0"
    "triangulate\0changeBrigthness\0a"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CrystalScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       5,    2,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   89,    2, 0x0a /* Public */,
      10,    1,   92,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x0a /* Public */,
      13,    0,   96,    2, 0x0a /* Public */,
      14,    0,   97,    2, 0x0a /* Public */,
      15,    0,   98,    2, 0x0a /* Public */,
      16,    1,   99,    2, 0x0a /* Public */,
      18,    0,  102,    2, 0x0a /* Public */,
      19,    1,  103,    2, 0x0a /* Public */,
      20,    0,  106,    2, 0x0a /* Public */,
      21,    1,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,

       0        // eod
};

void CrystalScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CrystalScene *_t = static_cast<CrystalScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->calibrateDistanceOK((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->calibrateCenterOK((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->loadImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->drawText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->activateCalibrateDistance(); break;
        case 5: _t->activatePickCenter(); break;
        case 6: _t->activatePickingPoints(); break;
        case 7: _t->activateRemovingPoints(); break;
        case 8: _t->getDistance((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->stampScale(); break;
        case 10: _t->setRotationAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->triangulate(); break;
        case 12: _t->changeBrigthness((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CrystalScene::*_t)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CrystalScene::calibrateDistanceOK)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CrystalScene::*_t)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CrystalScene::calibrateCenterOK)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CrystalScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_CrystalScene.data,
      qt_meta_data_CrystalScene,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CrystalScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CrystalScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CrystalScene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int CrystalScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void CrystalScene::calibrateDistanceOK(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CrystalScene::calibrateCenterOK(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
