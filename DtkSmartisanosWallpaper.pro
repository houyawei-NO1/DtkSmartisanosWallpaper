QT += core gui dtkwidget serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DtkSmartisanosWallpaper
TEMPLATE = app

CONFIG += c++11 link_pkgconfig

SOURCES += \
        main.cpp \
    dtksmartisanoswallpaper.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    dtksmartisanoswallpaper.h

DISTFILES += \
    hyw.ico

RC_ICONS = hyw.ico
