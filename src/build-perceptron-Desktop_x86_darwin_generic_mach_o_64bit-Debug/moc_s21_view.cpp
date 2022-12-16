/****************************************************************************
** Meta object code from reading C++ file 's21_view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../view/s21_view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 's21_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21_view_t {
    const uint offsetsAndSize[22];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_s21_view_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_s21_view_t qt_meta_stringdata_s21_view = {
    {
QT_MOC_LITERAL(0, 8), // "s21_view"
QT_MOC_LITERAL(9, 8), // "testDone"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 9), // "trainDone"
QT_MOC_LITERAL(29, 19), // "std::vector<double>"
QT_MOC_LITERAL(49, 6), // "values"
QT_MOC_LITERAL(56, 25), // "triggeredGroupActionUpper"
QT_MOC_LITERAL(82, 8), // "QAction*"
QT_MOC_LITERAL(91, 6), // "action"
QT_MOC_LITERAL(98, 39), // "on_crossValidationCheckBox_st..."
QT_MOC_LITERAL(138, 4) // "arg1"

    },
    "s21_view\0testDone\0\0trainDone\0"
    "std::vector<double>\0values\0"
    "triggeredGroupActionUpper\0QAction*\0"
    "action\0on_crossValidationCheckBox_stateChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21_view[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,
       3,    1,   39,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   42,    2, 0x08,    4 /* Private */,
       9,    1,   45,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void s21_view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<s21_view *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->testDone(); break;
        case 1: _t->trainDone((*reinterpret_cast< const std::vector<double>(*)>(_a[1]))); break;
        case 2: _t->triggeredGroupActionUpper((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: _t->on_crossValidationCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (s21_view::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&s21_view::testDone)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (s21_view::*)(const std::vector<double> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&s21_view::trainDone)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject s21_view::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_s21_view.offsetsAndSize,
    qt_meta_data_s21_view,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_s21_view_t
, QtPrivate::TypeAndForceComplete<s21_view, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const std::vector<double> &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAction *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *s21_view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21_view::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21_view.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int s21_view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void s21_view::testDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void s21_view::trainDone(const std::vector<double> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
