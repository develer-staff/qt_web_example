cmake_minimum_required(VERSION 3.5)

project(
    QtWeb
    VERSION 0.1
    LANGUAGES CXX
    DESCRIPTION "Qt and Web Integration Example")

#
# Build Options
#

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(
    Qt6
    COMPONENTS Widgets WebEngineWidgets
    REQUIRED)

set(SOURCES
    src/booklending.h
    src/booklistmodel.h
    src/bookshelfwidget.h
    src/mainwindow.h
    src/utils.h
    src/booklistmodel.cpp
    src/bookshelfwidget.cpp
    src/main.cpp
    src/mainwindow.cpp
)

qt_add_resources(PROJECT_SOURCES res/qtweb_resources.qrc)
qt_add_executable(qt_web_example ${SOURCES} ${PROJECT_SOURCES})

target_link_libraries(qt_web_example PRIVATE Qt::Widgets Qt::WebEngineWidgets)
