QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../main.cc \
    ../model/src/cave_generator.cc \
    ../model/src/eller_generator.cc \
    ../model/src/maze_file_saver.cc \
    ../model/src/maze_parser.cc \
    ../model/src/maze_wave_solver.cc \
    ../model/src/model.cc \
    src/maze_console_printer.cc \
    src/view.cc

HEADERS += \
    ../controller/inc/controller.h \
    ../model/inc/cave_generator.h \
    ../model/inc/eller_generator.h \
    ../model/inc/matrix.h \
    ../model/inc/maze.h \
    ../model/inc/maze_file_parser.h \
    ../model/inc/maze_file_saver.h \
    ../model/inc/maze_wave_solver.h \
    ../model/inc/model.h \
    inc/maze_console_printer.h \
    inc/qwidget_maze.h \
    inc/view.h

FORMS += \
    forms/view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
