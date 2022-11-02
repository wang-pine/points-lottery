/****************************************************************************
** Meta object code from reading C++ file 'goodsmanage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../GambleSystem/goodsmanage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'goodsmanage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GoodsManage_t {
    QByteArrayData data[6];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GoodsManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GoodsManage_t qt_meta_stringdata_GoodsManage = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GoodsManage"
QT_MOC_LITERAL(1, 12, 11), // "add_clicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "open_clicked"
QT_MOC_LITERAL(4, 38, 14), // "delete_clicked"
QT_MOC_LITERAL(5, 53, 12) // "save_clicked"

    },
    "GoodsManage\0add_clicked\0\0open_clicked\0"
    "delete_clicked\0save_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GoodsManage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GoodsManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GoodsManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->add_clicked(); break;
        case 1: _t->open_clicked(); break;
        case 2: _t->delete_clicked(); break;
        case 3: _t->save_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GoodsManage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GoodsManage::add_clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GoodsManage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GoodsManage::open_clicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GoodsManage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GoodsManage::delete_clicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GoodsManage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GoodsManage::save_clicked)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GoodsManage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GoodsManage.data,
    qt_meta_data_GoodsManage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GoodsManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GoodsManage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GoodsManage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GoodsManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GoodsManage::add_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GoodsManage::open_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GoodsManage::delete_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GoodsManage::save_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
