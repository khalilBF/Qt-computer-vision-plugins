#ifndef QPCLWIDGET_H
#define QPCLWIDGET_H

#include "QVTKWidget.h"
#include <pcl/visualization/pcl_visualizer.h>


// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>

class QPCLWidget : public QVTKWidget
{
    Q_OBJECT
public:
    explicit QPCLWidget(QWidget *parent = 0);
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer() const ;

private:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_;
signals:
    
public slots:
    
};

#endif // QPCLWIDGET_H
