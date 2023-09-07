QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sql_con.cpp \
    main.cpp \
    mainwindow.cpp \
    std_info.cpp \
    student_con.cpp \
    timetable.cpp

HEADERS += \
    Sql_con.h \
    database_info.h \
    mainwindow.h \
    std_info.h \
    student_con.h \
    timetable.h

FORMS += \
    mainwindow.ui \
    std_info.ui \
    student_con.ui \
    timetable.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

#LIBS += -LC:\oraclexe\app\oracle\product\11.2.0\server\lib -lORACORE11 -lorahasgen11

