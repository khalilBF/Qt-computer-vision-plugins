CONFIG      += designer plugin debug_and_release
TARGET      = $$qtLibraryTarget(filebuttonplugin)
TEMPLATE    = lib

HEADERS     = filebuttonplugin.h
SOURCES     = filebuttonplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(filebutton.pri)
