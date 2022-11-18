#include "s21_view.h"

#include <QApplication>

int main(int argc, char *argv[]) {

    setlocale(LC_NUMERIC, "C");
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/resource/qrc/icon.png"));
    s21_view w;
    w.show();
    return a.exec();
}
