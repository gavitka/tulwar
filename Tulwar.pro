#-------------------------------------------------
#
# Project created by QtCreator 2017-07-03T23:19:36
#
#-------------------------------------------------

QT       += core gui widgets

CONFIG += c++11

TARGET = Tulwar
TEMPLATE = app

INCLUDEPATH += include
LIBS += -Llib -lHookDll
LIBS += -lUser32

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        widget.cpp \
    settingswindow.cpp \
    NcFramelessHelper/NcFramelessHelper.cpp \
    kheventfilter.cpp

HEADERS  += widget.h \
    settingswindow.h \
    NcFramelessHelper/NcFramelessHelper.h \
    kheventfilter.h

# QMAKE_PRE_LINK += $$quote(copy /y HookDll\Release\HookDll.dll Debug & )
# QMAKE_PRE_LINK += $$quote(copy /y HookDll\Release\HookDll.dll Release & )
# QMAKE_PRE_LINK += $$quote(copy /y HookDll\HookDll\HookDll.h include & )
# QMAKE_PRE_LINK += $$quote(copy /y HookDll\HookDll\stdafx.h include & )
# QMAKE_PRE_LINK += $$quote(copy /y HookDll\HookDll\targetver.h include & )
# QMAKE_PRE_LINK += $$quote(copy /y HookDll\Release\HookDll.lib lib )
