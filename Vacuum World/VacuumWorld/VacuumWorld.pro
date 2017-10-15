TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    perception.cpp \
    enviroment.cpp \
    action.cpp \
    agent.cpp \
    tabledrivenagent.cpp \
    simplereflexagent.cpp

HEADERS += \
    header.h \
    perception.h \
    enviroment.h \
    action.h \
    agent.h \
    tabledrivenagent.h \
    simplereflexagent.h

