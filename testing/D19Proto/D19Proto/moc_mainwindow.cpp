/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Jul 24 12:40:17 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      45,   39,   11,   11, 0x08,
      86,   39,   11,   11, 0x08,
     117,  112,   11,   11, 0x08,
     172,  155,   11,   11, 0x08,
     242,   11,   11,   11, 0x08,
     275,  112,   11,   11, 0x08,
     308,   11,   11,   11, 0x08,
     328,  323,   11,   11, 0x08,
     380,  323,   11,   11, 0x08,
     432,  428,   11,   11, 0x08,
     456,   11,   11,   11, 0x08,
     489,  428,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_action_Open_triggered()\0"
    "value\0on_horizontalScrollBar_valueChanged(int)\0"
    "on_dial_valueChanged(int)\0arg1\0"
    "on_doubleSpinBox_valueChanged(double)\0"
    "current,previous\0"
    "on_numor_Widget_currentItemChanged(QListWidgetItem*,QListWidgetItem*)\0"
    "on_pushButton_openFile_pressed()\0"
    "on_spinBox_max_valueChanged(int)\0"
    "deleteNumors()\0item\0"
    "on_numor_Widget_itemDoubleClicked(QListWidgetItem*)\0"
    "on_numor_Widget_itemActivated(QListWidgetItem*)\0"
    "pos\0ShowContextMenu(QPoint)\0"
    "on_pushButton_PeakFind_clicked()\0"
    "on_textLogger_customContextMenuRequested(QPoint)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_action_Open_triggered(); break;
        case 1: _t->on_horizontalScrollBar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_doubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_numor_Widget_currentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 5: _t->on_pushButton_openFile_pressed(); break;
        case 6: _t->on_spinBox_max_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->deleteNumors(); break;
        case 8: _t->on_numor_Widget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->on_numor_Widget_itemActivated((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->ShowContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_PeakFind_clicked(); break;
        case 12: _t->on_textLogger_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
