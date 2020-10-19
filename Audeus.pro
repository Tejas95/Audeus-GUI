#-------------------------------------------------
#
# Project created by QtCreator 2020-06-16T11:35:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Audeus
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += src/main.cpp\
    src/Gate.cpp \
    src/Limiter.cpp \
    src/gettingstarted.cpp \
    src/input_loudness.cpp \
    src/mainwindow.cpp \
    src/Filter.cpp \
    src/Audeus.cpp \
    src/Gain.cpp \
    src/Loudness.cpp \
    src/noise_1.cpp \
    src/noise_2.cpp \
    src/noise_3.cpp \
    src/noise_4.cpp \
    src/noise_5.cpp \
    src/noise_6.cpp \
    src/pawrapper.cpp

HEADERS  += inc/mainwindow.h \
    inc/Audeus.h \
    inc/Definitions.h \
    inc/Filter.h \
    inc/Gain.h \
    inc/Gate.h \
    inc/Limiter.h \
    inc/Loudness.h \
    inc/gettingstarted.h \
    inc/input_loudness.h \
    inc/noise_1.h \
    inc/noise_2.h \
    inc/noise_3.h \
    inc/noise_4.h \
    inc/noise_5.h \
    inc/noise_6.h \
    inc/pawrapper.h


FORMS += ui/mainwindow.ui \
    ui/gettingstarted.ui \
    ui/input_loudness.ui \
    ui/noise_1.ui \
    ui/noise_2.ui \
    ui/noise_3.ui \
    ui/noise_4.ui \
    ui/noise_5.ui \
    ui/noise_6.ui

INCLUDEPATH += inc \
    portaudio/include \


LIBS += C:\Users\temanjunath.ADHARMAN\Desktop\Audeus\portaudio\build\msvc\x64\Release\portaudio_x64.lib


#DISTFILES += \
#    libportaudio.a
