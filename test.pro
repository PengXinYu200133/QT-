
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c99
CONFIG += c++17
CONFIG += staticlib
QT += core gui sql
QT += serialport
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    available_room_list.cpp \
    card_replacement.cpp \
    check_out.cpp \
    esp8266.cpp \
    in.cpp \
    in_optroomtype.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    newroom.cpp \
    quick_check_in.cpp \
    quick_reservation.cpp \
    report_the_loss_of.cpp \
    reservation.cpp \
    reservation_list.cpp

HEADERS += \
    available_room_list.h \
    card_replacement.h \
    check_out.h \
    esp8266.h \
    in.h \
    in_optroomtype.h \
    loginwindow.h \
    mainwindow.h \
    newroom.h \
    quick_check_in.h \
    quick_reservation.h \
    report_the_loss_of.h \
    reservation.h \
    reservation_list.h

FORMS += \
    available_room_list.ui \
    card_replacement.ui \
    check_out.ui \
    in.ui \
    in_optroomtype.ui \
    loginwindow.ui \
    mainwindow.ui \
    newroom.ui \
    quick_check_in.ui \
    quick_reservation.ui \
    report_the_loss_of.ui \
    reservation.ui \
    reservation_list.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
