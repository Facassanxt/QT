/****************************************************************************
** Meta object code from reading C++ file 'editperson.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../editperson.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editperson.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditPerson_t {
    QByteArrayData data[8];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditPerson_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditPerson_t qt_meta_stringdata_EditPerson = {
    {
QT_MOC_LITERAL(0, 0, 10), // "EditPerson"
QT_MOC_LITERAL(1, 11, 22), // "on_recieveData_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "long long int"
QT_MOC_LITERAL(4, 49, 2), // "id"
QT_MOC_LITERAL(5, 52, 16), // "on_recieveAccess"
QT_MOC_LITERAL(6, 69, 6), // "access"
QT_MOC_LITERAL(7, 76, 15) // "on_Edit_clicked"

    },
    "EditPerson\0on_recieveData_clicked\0\0"
    "long long int\0id\0on_recieveAccess\0"
    "access\0on_Edit_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditPerson[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    1,   32,    2, 0x0a /* Public */,
       7,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void EditPerson::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EditPerson *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_recieveData_clicked((*reinterpret_cast< long long int(*)>(_a[1]))); break;
        case 1: _t->on_recieveAccess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_Edit_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EditPerson::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_EditPerson.data,
    qt_meta_data_EditPerson,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EditPerson::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditPerson::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditPerson.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int EditPerson::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
