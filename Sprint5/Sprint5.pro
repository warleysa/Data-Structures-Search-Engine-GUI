TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


SOURCES += main.cpp \
    Indexer.cpp \
    HashTable.cpp \
    Entry.cpp

HEADERS += \
    csv.h \
    HashTable.h \
    docobject.h \
    wordobject.h \
    userinterface_nonGUI.h \
    IndexInterface.h \
    Indexer.h \
    HashTable.h \
    Entry.h

DISTFILES += \
    notesParseIndex
