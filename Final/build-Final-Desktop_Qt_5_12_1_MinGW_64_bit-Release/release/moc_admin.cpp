/****************************************************************************
** Meta object code from reading C++ file 'admin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../admin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Admin_t {
    QByteArrayData data[12];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Admin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Admin_t qt_meta_stringdata_Admin = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Admin"
QT_MOC_LITERAL(1, 6, 12), // "signal_admin"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 22), // "on_recieveData_clicked"
QT_MOC_LITERAL(4, 43, 13), // "long long int"
QT_MOC_LITERAL(5, 57, 2), // "id"
QT_MOC_LITERAL(6, 60, 24), // "on_pushButtonAdd_clicked"
QT_MOC_LITERAL(7, 85, 25), // "on_pushButtonEdit_clicked"
QT_MOC_LITERAL(8, 111, 27), // "on_pushButtonDelete_clicked"
QT_MOC_LITERAL(9, 139, 22), // "on_pushButton1_clicked"
QT_MOC_LITERAL(10, 162, 22), // "on_pushButton3_clicked"
QT_MOC_LITERAL(11, 185, 22) // "on_pushButton2_clicked"

    },
    "Admin\0signal_admin\0\0on_recieveData_clicked\0"
    "long long int\0id\0on_pushButtonAdd_clicked\0"
    "on_pushButtonEdit_clicked\0"
    "on_pushButtonDelete_clicked\0"
    "on_pushButton1_clicked\0on_pushButton3_clicked\0"
    "on_pushButton2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Admin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   55,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Int,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Admin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Admin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->signal_admin();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->on_recieveData_clicked((*reinterpret_cast< long long int(*)>(_a[1]))); break;
        case 2: _t->on_pushButtonAdd_clicked(); break;
        case 3: _t->on_pushButtonEdit_clicked(); break;
        case 4: _t->on_pushButtonDelete_clicked(); break;
        case 5: _t->on_pushButton1_clicked(); break;
        case 6: _t->on_pushButton3_clicked(); break;
        case 7: _t->on_pushButton2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = int (Admin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Admin::signal_admin)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Admin::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Admin.data,
    qt_meta_data_Admin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Admin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Admin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Admin.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Admin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
int Admin::signal_admin()
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
