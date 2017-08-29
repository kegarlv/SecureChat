QT += qml quick network

CONFIG += c++14

SOURCES += src/Backend.cpp \
           src/ContactInfo.cpp \
           src/CurrentUser.cpp \
           src/Dialog.cpp \
           src/main.cpp \
           src/Message.cpp \
           src/User.cpp \
    request.cpp

HEADERS += src/Backend.h \
           src/ContactInfo.h \
           src/CurrentUser.h \
           src/Dialog.h \
           src/Message.h \
           src/User.h \
           libs/json.h \
    request.h

RESOURCES += src/qml.qrc

