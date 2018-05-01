TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    lib/pen.cpp \
    fractais.cpp

HEADERS += \
    lib/sfLine.h \
    lib/pen.h


CONFIG += c++11
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
