#include "cvimagewidget.h"
#include "cvimagewidgetplugin.h"

#include <QtPlugin>

CVImageWidgetPlugin::CVImageWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void CVImageWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;
    
    // Add extension registrations, etc. here
    
    m_initialized = true;
}

bool CVImageWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *CVImageWidgetPlugin::createWidget(QWidget *parent)
{
    return new CVImageWidget(parent);
}

QString CVImageWidgetPlugin::name() const
{
    return QLatin1String("CVImageWidget");
}

QString CVImageWidgetPlugin::group() const
{
    return QLatin1String("Khalil");
}

QIcon CVImageWidgetPlugin::icon() const
{
    return QIcon();
}

QString CVImageWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString CVImageWidgetPlugin::whatsThis() const
{
    return QLatin1String("Widget Qt et OpenCV");
}

bool CVImageWidgetPlugin::isContainer() const
{
    return false;
}

QString CVImageWidgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"CVImageWidget\" name=\"cVImageWidget\">\n</widget>\n");
}

QString CVImageWidgetPlugin::includeFile() const
{
    return QLatin1String("cvimagewidget.h");
}

Q_EXPORT_PLUGIN2(cvimagewidgetplugin, CVImageWidgetPlugin)
