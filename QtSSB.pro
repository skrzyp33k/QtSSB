QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addaddressdialog.cpp \
    addmaildialog.cpp \
    addphonedialog.cpp \
    contactadddialog.cpp \
    main.cpp \
    mainwindow.cpp \
    serverconnectdialog.cpp \
    ssbaddress.cpp \
    ssbcontact.cpp \
    ssbmail.cpp \
    ssbphone.cpp \
    ssbuser.cpp \
    useradddialog.cpp \
    userlogindialog.cpp \
    userpassdialog.cpp

HEADERS += \
    addaddressdialog.h \
    addmaildialog.h \
    addphonedialog.h \
    contactadddialog.h \
    mainwindow.h \
    serverconnectdialog.h \
    ssbaddress.h \
    ssbcontact.h \
    ssbmail.h \
    ssbphone.h \
    ssbuser.h \
    useradddialog.h \
    userlogindialog.h \
    userpassdialog.h

FORMS += \
    addaddressdialog.ui \
    addmaildialog.ui \
    addphonedialog.ui \
    contactadddialog.ui \
    mainwindow.ui \
    serverconnectdialog.ui \
    useradddialog.ui \
    userlogindialog.ui \
    userpassdialog.ui

TRANSLATIONS += \
    QtSSB_pl_PL.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=

RC_ICONS = logo.ico
