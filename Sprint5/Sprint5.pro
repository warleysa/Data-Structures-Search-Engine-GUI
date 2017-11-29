QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app
TEMPLATE += app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    Indexer.cpp \
    HashTable.cpp \
    Entry.cpp \
    tag.cpp \
    page.cpp \
    main.cpp \
    parser.cpp \
    mainwindow.cpp

HEADERS += \
    HashTable.h \
    userinterface_nonGUI.h \
    IndexInterface.h \
    Indexer.h \
    HashTable.h \
    Entry.h \
    csv.h \
    tag.h \
    Entry.h \
    page.h \
    parser.h \
    mainwindow.h

DISTFILES += \
    notesParseIndex

FORMS += \
    mainwindow.ui
