QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app
TEMPLATE += app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
DEFINES += QT_DEPRECATED_WARNINGS
-Wl,--large-address-aware

SOURCES += \
    main.cpp \
    tag.cpp \
    qword.cpp \
    query.cpp \
    porter2_stemmer.cpp \
    parser.cpp \
    page.cpp \
    mainwindow.cpp \
    Indexer.cpp

FORMS += \
    mainwindow.ui

DISTFILES += \
    notesParseIndex

HEADERS += \
    csv.h \
    Indexer.h \
    word.h \
    HashTable.h \
    userinterface_nonGUI.h \
    tag.h \
    qword.h \
    query.h \
    porter2_stemmer.h \
    parser.h \
    page.h \
    mainwindow.h \
    IndexInterface.h
