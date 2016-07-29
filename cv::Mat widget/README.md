# cvImageWidget plugin for Qt Creator

##Description
An cv::Mat viewer compatible with Qt. The widget supports image streams and automatic updates.

##requirements
This plugin requires:
- Qt4 Library
- OpenCV 2.6

##Installation
In the CMakeLists.txt, change your Qt plugins directories, include directory, and Qt library directory with directories of your system. In the source folder, execute cmake && make && make install commands.

##Usage
CVImageWidget will appear in Qt Designer plugins. Drag and Drop the widget into your GUI and link to cvimagewidget.so library for compilation.
