cmake_minimum_required(VERSION 2.8)

set(PROJECT QCVPlugin)
project(${PROJECT})

# Needed to compile against ui and moc generated files
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(SOURCES
    cvimagewidgetplugin.cpp
    cvimagewidget.cpp

)

set(HEADERS

    cvimagewidgetplugin.h
    cvimagewidget.h
)

#Find Qt and OpenCV
find_package(Qt4 REQUIRED QtCore QtGui QtDesigner)
find_package( OpenCV REQUIRED )


set(QT_USE_QTDESIGNER TRUE)
include(${QT_USE_FILE})


include_directories(${OpenCV_INCLUDE_DIRS})

qt4_wrap_cpp(HEADERS_MOC ${HEADERS})
#qt4_wrap_ui(FORMS_HEADERS ${FORMS})
qt4_add_resources(RESOURCES_RCC ${RESOURCES})

# These defines are exhaustive, not all of them are useful.
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_NO_DEBUG)
add_definitions(-DQT_SHARED)
add_definitions(-DQDESIGNER_EXPORT_WIDGETS)

#${FORMS_HEADERS}
add_library(${PROJECT} SHARED
    ${SOURCES}
    ${HEADERS_MOC}
    ${RESOURCES_RCC}
)
target_link_libraries(${PROJECT} 
                      ${QT_LIBRARIES}
                      ${OpenCV_LIBS}
                     )

# Install the library in QtDesigner plugin directory
install(TARGETS ${PROJECT}     DESTINATION ${QT_PLUGINS_DIR}/designer)
install(TARGETS ${PROJECT}     DESTINATION /opt/qtcreator-2.5.2/bin/designer)
install(TARGETS ${PROJECT}     DESTINATION /usr/lib/qt4/plugins/designer)
install(TARGETS ${PROJECT}     DESTINATION /usr/lib/x86_64-linux-gnu/)
