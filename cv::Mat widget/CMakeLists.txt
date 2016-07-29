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

#set(FORMS    widget.ui)
find_package(Qt4 REQUIRED QtCore QtGui QtDesigner)
set(QT_USE_QTDESIGNER TRUE)
include(${QT_USE_FILE})

find_package(VTK REQUIRED)
find_package(PCL 1.7.1 REQUIRED)
find_package( OpenCV REQUIRED )

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

include_directories(${OpenCV_INCLUDE_DIRS})

set(VTK_LIBRARIES   vtkRendering vtkGraphics vtkHybrid QVTK)

qt4_wrap_cpp(HEADERS_MOC ${HEADERS})
#qt4_wrap_ui(FORMS_HEADERS ${FORMS})
qt4_add_resources(RESOURCES_RCC ${RESOURCES})

# Here too, I'm not sure every define is necessary
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
target_link_libraries(${PROJECT} ${QT_LIBRARIES}
                      ${PCL_LIBRARIES} ${VTK_LIBRARIES}
                      ${OpenCV_LIBS})

# Install the library in QtDesigner plugin directory
install(TARGETS ${PROJECT}     DESTINATION ${QT_PLUGINS_DIR}/designer)
install(TARGETS ${PROJECT}     DESTINATION /opt/qtcreator-2.5.2/bin/designer)
install(TARGETS ${PROJECT}     DESTINATION /usr/lib/qt4/plugins/designer)
install(TARGETS ${PROJECT}     DESTINATION /usr/lib/x86_64-linux-gnu/)
