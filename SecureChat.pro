QT += qml quick network widgets

CONFIG += c++14

RESOURCES += src/qml.qrc

SOURCES += src/main.cpp \
    src/controllers/ContactController.cpp \
    src/controllers/DialogController.cpp \
    src/controllers/UserController.cpp \
    src/models/contactlist.cpp \
    src/models/messagelist.cpp \
    src/structs/ContactInfo.cpp \
    src/structs/Dialog.cpp \
    src/structs/Message.cpp \
    src/structs/User.cpp \
    src/utils/cipherhelper.cpp \
    src/utils/messageworker.cpp \
    src/utils/request.cpp \
    src/utils/firebaseapi.cpp \
    src/utils/restfirebaseapi.cpp \
    src/utils/cryptapi.cpp

HEADERS += \
    src/controllers/ContactController.h \
    src/controllers/DialogController.h \
    src/controllers/UserController.h \
    src/models/contactlist.h \
    src/models/messagelist.h \
    src/structs/ContactInfo.h \
    src/structs/Dialog.h \
    src/structs/Message.h \
    src/structs/User.h \
    src/utils/cipherhelper.h \
    src/utils/constants.h \
    src/utils/json.h \
    src/utils/messageworker.h \
    src/utils/request.h \
    src/utils/firebaseapi.h \
    src/utils/restfirebaseapi.h \
    src/utils/cryptapi.h

LIBS += -lcryptopp
