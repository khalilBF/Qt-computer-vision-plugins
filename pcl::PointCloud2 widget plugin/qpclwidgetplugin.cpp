#include "qpclwidget.h"
#include "qpclwidgetplugin.h"

#include <QtPlugin>

QPCLWidgetPlugin::QPCLWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QPCLWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;
    
    // Add extension registrations, etc. here
    
    m_initialized = true;
}

bool QPCLWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QPCLWidgetPlugin::createWidget(QWidget *parent)
{
    return new QPCLWidget(parent);
}

QString QPCLWidgetPlugin::name() const
{
    return QLatin1String("QPCLWidget");
}

QString QPCLWidgetPlugin::group() const
{
    return QLatin1String("Khalil");
}

QIcon QPCLWidgetPlugin::icon() const
{
    return QIcon(QLatin1String(":/QpclLogo.png"));
}

QString QPCLWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString QPCLWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool QPCLWidgetPlugin::isContainer() const
{
    return false;
}

QString QPCLWidgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QPCLWidget\" name=\"qPCLWidget\">\n</widget>\n");
}

QString QPCLWidgetPlugin::includeFile() const
{
    return QLatin1String("qpclwidget.h");
}

Q_EXPORT_PLUGIN2(qpclwidgetplugin, QPCLWidgetPlugin)
