#include "cvimagewidget.h"

CVImageWidget::CVImageWidget(QWidget *parent) :
    QWidget(parent)
{
}

QSize CVImageWidget::sizeHint() const
{
    return _qimage.size();
}

QSize CVImageWidget::minimumSizeHint() const
{
    return _qimage.size();
}

void CVImageWidget::showImage(const cv::Mat &image)
{
    // Convert the image to the RGB888 format
    switch (image.type()) {
    case CV_8UC1:
        cvtColor(image, _tmp, CV_GRAY2RGB);
        break;
    case CV_8UC3:
        cvtColor(image, _tmp, CV_BGR2RGB);
        break;
    }

    // QImage needs the data to be stored continuously in memory
    assert(_tmp.isContinuous());
    // Assign OpenCV's image buffer to the QImage. Note that the bytesPerLine parameter
   
    _qimage = QImage(_tmp.data, _tmp.cols, _tmp.rows, _tmp.cols*3, QImage::Format_RGB888);

    this->setFixedSize(image.cols, image.rows);

    repaint();
}

void CVImageWidget::paintEvent(QPaintEvent *e)
{
    // Display the image
    QPainter painter(this);
    painter.drawImage(QPoint(0,0), _qimage);
    painter.end();
}
