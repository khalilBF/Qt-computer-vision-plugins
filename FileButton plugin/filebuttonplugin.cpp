#include "filebutton.h"
#include "filebuttonplugin.h"

#include <QtPlugin>

FileButtonPlugin::FileButtonPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void FileButtonPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;
    
    // Add extension registrations, etc. here
    
    m_initialized = true;
}

bool FileButtonPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *FileButtonPlugin::createWidget(QWidget *parent)
{
    return new FileButton(parent);
}

QString FileButtonPlugin::name() const
{
    return QLatin1String("FileButton");
}

QString FileButtonPlugin::group() const
{
    return QLatin1String("Khalil");
}

QIcon FileButtonPlugin::icon() const
{
    return QIcon();
}

QString FileButtonPlugin::toolTip() const
{
    return QLatin1String("");
}

QString FileButtonPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool FileButtonPlugin::isContainer() const
{
    return false;
}

QString FileButtonPlugin::domXml() const
{
    return QLatin1String("<widget class=\"FileButton\" name=\"fileButton\">\n</widget>\n");
}

QString FileButtonPlugin::includeFile() const
{
    return QLatin1String("filebutton.h");
}

Q_EXPORT_PLUGIN2(filebuttonplugin, FileButtonPlugin)
