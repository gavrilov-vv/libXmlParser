#-------------------------------------------------
#
# Project created by QtCreator 2021-07-30T14:12:10
#
#-------------------------------------------------

QT       += network sql xml testlib concurrent

QT       -= gui

CONFIG += C++11

TEMPLATE = lib
CONFIG += staticlib


OBJECTS_DIR = generated_files
MOC_DIR     = generated_files
UI_DIR      = generated_files
RCC_DIR     = generated_files


SOURCES += \
    XmlParser.cpp

HEADERS += \
    Models.h \
    XmlParser.h \
    global_defs.h

DISTFILES += \
    Doxyfile \
    ../READMY

unix {

    DEPLOY_FOLDER = $$OUT_PWD/../../deploy_files/libxmlparser
    INCLUDE_FOLDER = $${DEPLOY_FOLDER}/include
    ARCHIVE_NAME = $${TARGET}.tar

    CONFIG(debug, debug|release) {

        message("Start DEBUG build to" $$OUT_PWD)
    }

    CONFIG(release, debug|release) {

        message("Start RELEASE build to" $$OUT_PWD)

    }


    tgt.path = $$DEPLOY_FOLDER
    tgt.files += $$OUT_PWD/lib$${TARGET}.a

    tgt1.path = $$INCLUDE_FOLDER
    tgt1.files += $$HEADERS

}

unix:!isEmpty(tgt.path): INSTALLS += tgt tgt1

