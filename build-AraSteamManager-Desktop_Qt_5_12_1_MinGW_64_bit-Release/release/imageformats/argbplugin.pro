TARGET  = argb
TEMPLATE = lib
CONFIG = qt plugin
VERSION = 1.0.0

HEADERS += argbhandler.h
SOURCES += argbplugin.cpp \
           argbhandler.cpp

target.path += $$[QT_INSTALL_PLUGINS]/imageformats
INSTALLS += target
