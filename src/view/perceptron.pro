QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 -fsanitize=address

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../controller/controller.cc \
    ../matrix/s21_matrix.cpp \
    ../matrix/s21_support_func.cc \
    ../model/data.cc \
    ../model/facade.cc \
    ../model/graph_network.cc \
    ../model/matrix.cc \
    ../model/metric.cpp \
    ../model/network.cc \
    ../model/neuron.cc \
    ../model/reader.cc \
    main.cpp \
    qcustomplot.cpp \
    render_scene.cpp \
    s21_view.cpp

HEADERS += \
    ../controller/controller.h \
    ../matrix/s21_matrix.h \
    ../model/data.h \
    ../model/facade.h \
    ../model/graph_network.h \
    ../model/matrix.h \
    ../model/metric.h \
    ../model/network.h \
    ../model/neuron.h \
    ../model/reader.h \
    qcustomplot.h \
    render_scene.h \
    s21_view.h

FORMS += \
    s21_view.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#ICON = icon.png

RESOURCES += \
    resource.qrc

DISTFILES += \
    qrc/icon.png \
    qrc/setting.png

