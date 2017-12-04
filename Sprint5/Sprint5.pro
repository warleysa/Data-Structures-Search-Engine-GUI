QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app
TEMPLATE += app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    page.cpp \
    main.cpp \
    parser.cpp \
    mainwindow.cpp \
    tag.cpp \
    query.cpp \
    qword.cpp \
    Results.cpp \
    Indexer.cpp \
    Entry.cpp \
    porter2_stemmer.cpp

HEADERS += \
    userinterface_nonGUI.h \
    IndexInterface.h \
    csv.h \
    tag.h \
    page.h \
    parser.h \
    mainwindow.h \
    query.h \
    qword.h \
    Results.h \
    Indexer.h \
    HashTable.h \
    Entry.h \
    porter2_stemmer.h

DISTFILES += \
    notesParseIndex

FORMS += \
    mainwindow.ui
