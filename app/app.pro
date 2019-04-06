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
        main.cpp \
        mainwindow.cpp \
    openglwidget.cpp \
    shaderprogram.cpp \
    flashcardmesh.cpp \
    textrenderer.cpp \
    flashcard.cpp \
    flashcardmanager.cpp \
    databasemanager.cpp \
    flashcardmodel.cpp \
    decorator.cpp \
    visualcomponent.cpp \
    borderdecorator.cpp \
    glyphfactory.cpp \
    character.cpp \
    glyph.cpp \
    glyphcontext.cpp \
    font.cpp \
    fontfactory.cpp \
    graphic.cpp \
    text.cpp \
    ractangle.cpp \
    button.cpp \
    shape.cpp \
    renderer.cpp \
    contextrenderer.cpp

HEADERS += \
        mainwindow.h \
    openglwidget.h \
    shaderprogram.h \
    flashcardmesh.h \
    textrenderer.h \
    flashcard.h \
    flashcardmanager.h \
    databasemanager.h \
    flashcardmodel.h \
    decorator.h \
    visualcomponent.h \
    borderdecorator.h \
    glyphfactory.h \
    character.h \
    glyph.h \
    glyphcontext.h \
    font.h \
    fontfactory.h \
    graphic.h \
    text.h \
    ractangle.h \
    button.h \
    shape.h \
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
