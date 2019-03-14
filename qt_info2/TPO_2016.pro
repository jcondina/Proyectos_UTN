QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(qextserialport/src/qextserialport.pri)

TARGET = TPO_2016
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    nuevo_usuario.cpp \
    eliminar_usuario.cpp \
    error_eliminar.cpp \
    confirmar_eliminar.cpp \
    display_datos.cpp \
    dialog.cpp\
    hled.cpp

HEADERS  += mainwindow.h \
    nuevo_usuario.h \
    eliminar_usuario.h \
    error_eliminar.h \
    confirmar_eliminar.h \
    display_datos.h \
    header.h \
    dialog.h \
    hled.h

FORMS    += mainwindow.ui \
    nuevo_usuario.ui \
    eliminar_usuario.ui \
    error_eliminar.ui \
    confirmar_eliminar.ui \
    display_datos.ui \
    dialog.ui

DISTFILES += \
    imagenes_usuarios/user-nopic.png \
    qextserialport/extserialport.prf.in \
    qextserialport/ChangeLog \
    qextserialport/LICENSE.md \
    qextserialport/README.md

SUBDIRS += \
    qextserialport/qextserialport.pro
