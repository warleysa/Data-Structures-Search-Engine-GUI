TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Entry.cpp \
    HashTable.cpp \
    Indexer.cpp

HEADERS += \
    Entry.h \
    IndexInterface.h \
    csv.h \
    HashTable.h \
    Indexer.h \
    docobject.h \
    wordobject.h \
    userinterface.h

DISTFILES += \
    notesParseIndex
