QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    parser.cpp \
    qgraphicsroundedrectitem.cpp \
    qrandidgenerator.cpp \
    serializer.cpp \
    task.cpp \
    taskcategory.cpp \
    taskeditorform.cpp \
    taskgraphicswidget.cpp

HEADERS += \
    mainwindow.h \
    parser.h \
    qgraphicsroundedrectitem.h \
    qrandidgenerator.h \
    serializer.h \
    task.h \
    taskcategory.h \
    taskeditorform.h \
    taskgraphicswidget.h

FORMS += \
    mainwindow.ui \
    taskeditorform.ui

TRANSLATIONS += \
    todo_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    data.qrc
