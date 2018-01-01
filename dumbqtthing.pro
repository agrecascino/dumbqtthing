TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

LIBS += -lglfw -lGLEW -lGL -lGLU -lglut -lportaudio -lpthread
QMAKE_CXXFLAGS = -std=c++11

HEADERS += \
    player.h
