QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Progetto
TEMPLATE = app


SOURCES += main.cpp\
    item.cpp \
    smartablet.cpp \
    computer.cpp \
    fisso.cpp \
    portatile.cpp \
    smartphone.cpp \
    tablet.cpp \
    paginamodifica.cpp \
    controller.cpp \
    catalogo.cpp \
    paginains.cpp \
    layoutcampicomputer.cpp \
    layoutcampismartablet.cpp \
    layoutcampifisso.cpp \
    model.cpp \
    layoutcampiportatile.cpp \
    layoutcampitablet.cpp \
    layoutcampismartphone.cpp \
    viewlistaprodotti.cpp \
    elementilistaprodotti.cpp

HEADERS += \
    item.h \
    smartablet.h \
    computer.h \
    fisso.h \
    portatile.h \
    smartphone.h \
    tablet.h \
    container.h \
    paginamodifica.h \
    controller.h \
    catalogo.h \
    paginains.h \
    layoutcampicomputer.h \
    layoutcampismartablet.h \
    layoutcampifisso.h \
    model.h \
    layoutcampiportatile.h \
    layoutcampitablet.h \
    layoutcampismartphone.h \
    viewlistaprodotti.h \
    elementilistaprodotti.h

