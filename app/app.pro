#-------------------------------------------------
#
# Project created by QtCreator 2018-07-31T18:32:21
#
#-------------------------------------------------

QT       += core gui widgets opengl sql

TARGET = app
TEMPLATE = app

INCLUDEPATH += /usr/local/include/freetype2/
LIBS += -L/usr/local/lib -lfreetype


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    basicwidget.cpp \
    button.cpp \
    label.cpp \
    labelrenderer.cpp \
        main.cpp \
        mainwindow.cpp \
    openglwidget.cpp \
    pathmanager.cpp \
    shaderprogram.cpp \
    flashcardmesh.cpp \
    textrenderer.cpp \
    flashcard.cpp \
    flashcardmanager.cpp \
    databasemanager.cpp \
    flashcardmodel.cpp \
    character.cpp \
    font.cpp \
    fontfactory.cpp \
    renderer.cpp \
    contextrenderer.cpp

HEADERS += \
    basicwidget.h \
    button.h \
    label.h \
    labelrenderer.h \
        mainwindow.h \
    openglwidget.h \
    pathmanager.h \
    shaderprogram.h \
    flashcardmesh.h \
    textrenderer.h \
    flashcard.h \
    flashcardmanager.h \
    databasemanager.h \
    flashcardmodel.h \
    character.h \
    font.h \
    fontfactory.h \
    renderer.h \
    contextrenderer.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    flashcard.vert \
    flashcard.frag \
    font.frag \
    font.vert
