#include "filebutton.h"
#include <QFileDialog>
#include <QMessageBox>


FileButton::FileButton(QWidget *parent) :
    QPushButton(parent)

{
    this->setText("Button");
    this->mode_ = false ; // 0 for open, 1 for save
    this->filename_.clear();
    this->extension_ = tr("txt") ;
    this->extension2_ = tr("(*.")+ this->extension_ +tr(")") ;
    connect(this, SIGNAL(clicked()) , this, SLOT(getFileName()) ) ;

}

void FileButton::setExtension(QString ext)
{
    this->extension_ = ext ;
    this->extension2_ = tr("(*.")+ this->extension_ +tr(")") ;
}

void FileButton::setMode(bool b)
{
    this->mode_ = b ;
}

bool FileButton::mode() const
{
    return this->mode_ ;
}

QString FileButton::extension() const
{
    return this->extension_ ;
}

QString FileButton::getNameVariable() const
{
    return this->filename_ ;
}

void FileButton::getFileName()
{
    this->filename_.clear();
    if(this->mode_){
        this->filename_ = QFileDialog::getSaveFileName(this,tr("Save File"),"./",this->extension2_) ;

    }else{
        this->filename_ = QFileDialog::getOpenFileName(this,tr("Open File"),"./",this->extension2_) ;

    }
    if(!this->filename_.isEmpty()){
        emit filename(filename_);
    }
}
