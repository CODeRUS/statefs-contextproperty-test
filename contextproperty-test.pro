TARGET = contextproperty-test

CONFIG += sailfishapp link_pkgconfig
PKGCONFIG += sailfishapp contextkit-statefs

SOURCES += src/contextproperty-test.cpp \
    src/statefsproperty.cpp

OTHER_FILES += qml/contextproperty-test.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    rpm/contextproperty-test.changes.in \
    rpm/contextproperty-test.spec
    contextproperty-test.desktop

HEADERS += \
    src/statefsproperty.h
