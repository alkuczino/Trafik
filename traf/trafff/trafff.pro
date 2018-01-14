#-------------------------------------------------
#
# Project created by QtCreator 2017-12-18T21:44:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = trafff
TEMPLATE = app


SOURCES += \
    Camera.cc \
    Car.cc \
    Config.cc \
    Element.cc \
    Map.cc \
    Moving.cc \
    NotMoving.cc \
    Pedestrian.cc \
    Road.cc \
    Simulator.cc \
    main.cpp

HEADERS  += \
    Camera.h \
    Car.h \
    Config.h \
    Element.h \
    Map.h \
    Moving.h \
    NotMoving.h \
    Pedestrian.h \
    Road.h \
    Simulator.h

FORMS    +=

DISTFILES += \
    Resources/car.png \
    Resources/road.png

RESOURCES += \
    img.qrc
