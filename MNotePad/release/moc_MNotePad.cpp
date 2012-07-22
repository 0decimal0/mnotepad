/****************************************************************************
** Meta object code from reading C++ file 'MNotePad.h'
**
** Created: Wed 6. Aug 11:29:06 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MNotePad.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MNotePad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MNotePad[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      23,    9,    9,    9, 0x0a,
      35,    9,    9,    9, 0x0a,
      45,    9,    9,    9, 0x0a,
      57,    9,    9,    9, 0x0a,
      67,    9,    9,    9, 0x0a,
      74,    9,    9,    9, 0x0a,
      84,    9,    9,    9, 0x0a,
     103,   96,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MNotePad[] = {
    "MNotePad\0\0nouveauTab()\0ouvrirTab()\0"
    "saveTab()\0precedent()\0suivant()\0font()\0"
    "apropos()\0fermerTab()\0window\0"
    "changerTab(QMdiSubWindow*)\0"
};

const QMetaObject MNotePad::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MNotePad,
      qt_meta_data_MNotePad, 0 }
};

const QMetaObject *MNotePad::metaObject() const
{
    return &staticMetaObject;
}

void *MNotePad::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MNotePad))
	return static_cast<void*>(const_cast< MNotePad*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MNotePad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: nouveauTab(); break;
        case 1: ouvrirTab(); break;
        case 2: saveTab(); break;
        case 3: precedent(); break;
        case 4: suivant(); break;
        case 5: font(); break;
        case 6: apropos(); break;
        case 7: fermerTab(); break;
        case 8: changerTab((*reinterpret_cast< QMdiSubWindow*(*)>(_a[1]))); break;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
