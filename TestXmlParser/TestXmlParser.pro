QT += testlib xml
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++11
CONFIG += no_testcase_installs

TEMPLATE = app

SOURCES +=  tst_testxmlparser.cpp

OBJECTS_DIR = generated_files
MOC_DIR     = generated_files
UI_DIR      = generated_files
RCC_DIR     = generated_files



RESOURCES += \
    testres.qrc


unix:!macx: LIBS += -L$$PWD/../deploy_files/libxmlparser/ -lXmlParser

INCLUDEPATH += $$PWD/../deploy_files/libxmlparser/include
DEPENDPATH += $$PWD/../deploy_files/libxmlparser/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../deploy_files/libxmlparser/libXmlParser.a

