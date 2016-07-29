#ifndef FILEBUTTON_H
#define FILEBUTTON_H

#include <QString>
#include <QPushButton>
#include <QMouseEvent>
class FileButton : public QPushButton
{
    Q_OBJECT
public:
    // notyfy when filename is changed
    Q_PROPERTY(QString filename_ READ getNameVariable NOTIFY filename)
    // extension can be read or forced to have specific value
    Q_PROPERTY(QString extension_ READ extension WRITE setExtension )
    // set mode or get mode, no need to notify
    Q_PROPERTY(bool mode_ READ mode WRITE setMode)

    explicit FileButton(QWidget *parent = 0);

    //-----------------setters
    void setExtension(QString ext) ;
    void setMode(bool b);

    //-----------------getters
    bool mode() const;
    QString extension() const ;
    QString getNameVariable() const ;

signals:
    void filename(QString filename_ ) ;
    
private slots:
    void getFileName() ;
private:
    bool mode_ ;
    QString filename_ , extension2_ , extension_;

};

#endif // FILEBUTTON_H
