TEMPLATE = app
TEMPLATE += app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt


SOURCES += \
    Indexer.cpp \
    HashTable.cpp \
    Entry.cpp \
    tag.cpp \
    page.cpp \
    main.cpp \
    parser.cpp

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
    parser.h

DISTFILES += \
    notesParseIndex
