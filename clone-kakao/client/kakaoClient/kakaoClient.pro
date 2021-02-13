QT += gui qml

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        kakaowindow.cpp \
        main.cpp

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

INSTALLS = no_build

MOC_DIR = .moc/
OBJECTS_DIR = .obj/
RCC_DIR = .rcc/
DESTDIR = build/

HEADERS += \
    kakaowindow.h

RESOURCES += \
    image.qrc \
    image.qrc \
    qml.qrc

QMAKE_CLEAN += \
    .obj/* \
    .moc/* \
