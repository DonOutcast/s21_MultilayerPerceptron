#include "s21_view.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/resource/icon.icns"));
    s21_view w;
    w.show();
    return a.exec();
}
