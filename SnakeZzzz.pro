TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    okno_gry.cpp \
    gra_gameplay.cpp

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += $$PWD/../SFML-2.4.2/include
INCLUDEPATH += $$PWD/../SFML-2.4.2/lib

HEADERS += \
    okno_gry.h \
    gra_gameplay.h
