#-------------------------------------------------
#
# Project created by QtCreator 2015-07-26T13:53:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VLSMSubnettingPracticeUI
TEMPLATE = app

HEADERS  += vlsmsubnettingpracticeui.h \
    ipaddress.h \
    subnetservice.h \
    subnetinformation.h

SOURCES += main.cpp\
        vlsmsubnettingpracticeui.cpp \
    ipaddress.cpp \
    subnetservice.cpp

FORMS    += vlsmsubnettingpracticeui.ui
