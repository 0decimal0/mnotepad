#include <QApplication>
#include <QtGui>
#include "MNotePad.h"

int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    MNotePad notepad;
    notepad.show();
    return app.exec();
    }
