TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


SOURCES += main.cpp

HEADERS += \
    csv.h \
    HashTable.h \
    docobject.h \
    wordobject.h \
    userinterface_nonGUI.h

DISTFILES += \
    notesParseIndex
