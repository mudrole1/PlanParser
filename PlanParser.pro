#-------------------------------------------------
#
# Project created by QtCreator 2017-12-17T15:11:20
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = PlanParser
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11

TEMPLATE = app


SOURCES += main.cpp \
    literal.cpp \
    term.cpp \
    type.cpp \
    parsepddlfiles.cpp

HEADERS += \
    literal.h \
    term.h \
    type.h \
    parsepddlfiles.h
