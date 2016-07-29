#include "qpclwidget.h"

QPCLWidget::QPCLWidget(QWidget *parent) :
    QVTKWidget(parent)
{
    // Set up the QVTK window
    this->viewer_.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
    this->SetRenderWindow(this->viewer_->getRenderWindow());
    this->viewer_->setupInteractor(this->GetInteractor() , this->GetRenderWindow()) ;
    this->update();

}

boost::shared_ptr<pcl::visualization::PCLVisualizer> QPCLWidget::viewer() const
{
    return this->viewer_ ;
}
