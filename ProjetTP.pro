#-------------------------------------------------
#
# Project created by QtCreator 2017-03-31T10:35:26
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetTP
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


SOURCES += main.cpp\
    idwindow.cpp \
    addpatient.cpp \
    mainwindow.cpp \
    addhealthcareoperator.cpp \
    about.cpp \
    c_init_bd.cpp \
    patientDAO.cpp \
    bdhandler.cpp \
    patient.cpp \
    ressource.cpp \
    ressourceDAO.cpp \
    type.cpp \
    compte.cpp \
    consult.cpp \
    typeDAO.cpp \
    compteDAO.cpp \
    consultDAO.cpp

HEADERS  += mainwindow.h \
    idwindow.h \
    addpatient.h \
    addhealthcareoperator.h \
    about.h \
    c_init_bd.h \
    patientDAO.h \
    bdhandler.h \
    patient.h \
    ressource.h \
    ressourceDAO.h \
    type.h \
    compte.h \
    consult.h \
    typeDAO.h \
    compteDAO.h \
    consultDAO.h

FORMS    += mainwindow.ui \
    idwindow.ui \
    addpatient.ui \
    addhealthcareoperator.ui \
    about.ui

DISTFILES +=
