cmake_minimum_required(VERSION 3.5)

project(AirportInspector VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core Concurrent Sql PrintSupport Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Concurrent Sql PrintSupport Gui)

set(PROJECT_SOURCES
        main.cpp
        airportinspector.cpp
        airportinspector.h
        airportinspector.ui
        workloadschedule.h
        workloadschedule.cpp
        workloadschedule.ui
        databaseconnection.h
        databaseconnection.cpp
        databasecache.h
        databasecache.cpp
        databaserequest.h
        databaserequest.cpp
        databasequeryairports.h
        databasequeryairports.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(AirportInspector
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

else()
    if(ANDROID)
        add_library(AirportInspector SHARED
            ${PROJECT_SOURCES}
        )

    else()
        add_executable(AirportInspector
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/library)

target_link_libraries(AirportInspector PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                               Qt${QT_VERSION_MAJOR}::Core
                                               Qt${QT_VERSION_MAJOR}::Concurrent
                                               Qt${QT_VERSION_MAJOR}::Sql
                                               Qt${QT_VERSION_MAJOR}::PrintSupport
                                               Qt${QT_VERSION_MAJOR}::Gui
                                               libcrypto-3-x64
                                               libiconv-2
                                               libintl-9
                                               libpq
                                               libssl-3-x64
                                               qcustomplot2
                                               qcustomplotd2)


if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.AirportInspector)
endif()
set_target_properties(AirportInspector PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS AirportInspector
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(AirportInspector)
endif()
