QT += qml quick network widgets

CONFIG += c++14

SOURCES += src/messagelist.cpp \
    src/contactlist.cpp \
    src/messageworker.cpp \
    src/Backend.cpp \
    src/ContactInfo.cpp \
    src/CurrentUser.cpp \
    src/Dialog.cpp \
    src/main.cpp \
    src/Message.cpp \
    src/User.cpp \
    src/request.cpp \
    src/cipherhelper.cpp

HEADERS += src/Backend.h \
           src/ContactInfo.h \
           src/CurrentUser.h \
           src/Dialog.h \
           src/Message.h \
           src/User.h \
           libs/json.h \
    src/request.h \
    src/messagelist.h \
    src/contactlist.h \
    src/messageworker.h \
    src/cipherhelper.h

RESOURCES += src/qml.qrc

LIBS += -lcryptopp
